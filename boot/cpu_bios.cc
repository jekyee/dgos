#include "cpu.h"
#include "paging.h"
#include "gdt_sel.h"
#include "screen.h"
#include "bioscall.h"

bool need_a20_toggle;

void cpu_a20_enterpm()
{
    if (need_a20_toggle)
        toggle_a20(1);
}

void cpu_a20_exitpm()
{
    if (need_a20_toggle)
        toggle_a20(0);
}

bool toggle_a20(uint8_t enable)
{
    enum struct a20_method {
        unknown,
        bios,
        port92,
        keybd,
        unspecified
    };

    static a20_method method = a20_method::unknown;

    bios_regs_t regs{};

    if (method == a20_method::unknown) {
        // Try to use the BIOS
        regs.eax = enable ? 0x2401 : 0x2400;
        bioscall(&regs, 0x15);
        if (!regs.flags_CF()) {
            method = a20_method::bios;
            return true;
        }

        // Ask the BIOS which method to use
        regs.eax = 0x2403;
        bioscall(&regs, 0x15);
        if (!regs.flags_CF() && (regs.ebx & 3)) {
            if (regs.ebx & 1) {
                method = a20_method::keybd;
            } else {
                method = a20_method::port92;
            }
        } else {
            PRINT("BIOS doesn't support A20! Guessing port 0x92...");
            method = a20_method::port92;
        }
    }

    switch (method) {
    case a20_method::bios:
        regs.eax = enable ? 0x2401 : 0x2400;
        bioscall(&regs, 0x15);
        return !regs.flags_CF();

    case a20_method::port92:
        uint8_t value;
        enable = (enable != 0) << 1;
        __asm__ __volatile__ (
            "inb $0x92,%[value]\n\t"
            "andb $~2,%[value]\n\t"
            "orb %[enable],%[value]\n\t"
            "wbinvd\n\t"
            "outb %1,$0x92\n\t"
            : [enable] "+c" (enable)
            , [value] "=a" (value)
        );
        return true;

    case a20_method::keybd:
        // Command write
        while (inb(0x64) & 2);
        outb(0x64, 0xD1);

        // Write command
        while (inb(0x64) & 2);
        outb(0x60, enable ? 0xDF : 0xDD);

        // Wait for empty and cover signal propagation delay
        while (inb(0x64) & 2);

        return true;

    default:
        return false;

    }
}

void run_code64(void (*fn)(void *), void *arg)
{
    uint32_t pdbr = paging_root_addr();

    struct params_t {
        void (*fn)(void*);
        void *arg;
        uint32_t pdbr;
    } params = {
        fn,
        arg,
        pdbr
    };

    __asm__ __volatile__ (
        // Enable CR4.PAE (bit 5)
        "movl %%cr4,%%eax\n\t"
        "btsl $%c[cr4_pae_bit],%%eax\n\t"
        "orl %[gp_available],%%eax\n\t"
        "movl %%eax,%%cr4\n\t"

        // Load PDBR
        "movl %c[pdbr_ofs](%[params]),%%eax\n\t"
        "movl %%eax,%%cr3\n\t"

        // Enable long mode IA32_EFER.LME (bit 8) MSR 0xC0000080
        // and if available, enable no-execute bit in paging
        "movl $%c[msr_efer],%%ecx\n"
        "rdmsr\n\t"
        "btsl $%c[msr_efer_lme_bit],%%eax\n\t"
        "cmpw $0,%[nx_available]\n\t"
        "jz 0f\n\t"
        "btsl $%c[msr_efer_nx_bit],%%eax\n\t"
        "0:"
        "wrmsr\n\t"

        // Enable paging (CR0.PG (bit 31)
        "movl %%cr0,%%eax\n\t"
        "btsl $%c[cr0_pg_bit],%%eax\n\t"
        "movl %%eax,%%cr0\n\t"

        // Now in 64 bit compatibility mode (still really 32 bit)

        // Far jump to selector that has L bit set (64 bit)
        "lea 6+idtr_64,%%eax\n\t"
        "lcall %[gdt_code64],$0f\n\t"

        // Returned from long mode, back to compatibility mode

        // Load 32 bit data segments
        "movl %[gdt_data32],%%eax\n\t"
        "movw %%ax,%%ds\n\t"
        "movw %%ax,%%es\n\t"
        "movw %%ax,%%fs\n\t"
        "movw %%ax,%%ss\n\t"

        // Jump over 64 bit code
        "jmp 1f\n\t"

        // Long mode
        ".code64\n\t"
        "0:\n\t"

        "lidtq (%%eax)\n\t"

        // Load parameters
        "movl %c[fn_ofs](%[params]),%%eax\n\t"
        "movl %c[arg_ofs](%[params]),%%edi\n\t"

        "mov %%rsp,%%r15\n\t"
        "andq $-16,%%rsp\n\t"
        "call *%%rax\n\t"
        "mov %%r15,%%rsp\n\t"

        // Far return to 32 bit compatibility mode code segment
        "lret\n\t"

        "1:\n\t"
        ".code32\n\t"

        // Disable paging
        "mov %%cr0,%%eax\n\t"
        "btr $%c[cr0_pg_bit],%%eax\n\t"
        "mov %%eax,%%cr0\n\t"

        // Disable long mode
        "movl $%c[msr_efer],%%ecx\n"
        "rdmsr\n\t"
        "btr $%c[msr_efer_lme_bit],%%eax\n\t"
        "wrmsr\n\t"

        // Load 32 bit selectors
        "movl %[gdt_data32],%%eax\n\t"
        "movw %%ax,%%ds\n\t"
        "movw %%ax,%%es\n\t"
        "movw %%ax,%%fs\n\t"
        "movw %%ax,%%ss\n\t"

        // Load 32-bit code segment
        "ljmp %[gdt_code32],$0f\n\t"
        "nop\n\t"

        // 32-bit addressing mode reenabled
        ".code32\n\t"
        "0:\n\t"

        "lea 2+idtr_16,%%esi\n\t"
        "lidt (%%esi)\n\t"
        :
        : [params] "b" (&params)
        , [nx_available] "m" (nx_available)
        , [gp_available] "m" (gp_available)
        , [fn_ofs] "e" (offsetof(params_t, fn))
        , [arg_ofs] "e" (offsetof(params_t, arg))
        , [pdbr_ofs] "e" (offsetof(params_t, pdbr))
        , [gdt_code64] "n" (GDT_SEL_KERNEL_CODE64)
        , [gdt_data64] "n" (GDT_SEL_USER_DATA | 3)
        , [gdt_stkseg] "n" (GDT_SEL_KERNEL_DATA)
        , [gdt_code32] "n" (GDT_SEL_PM_CODE32)
        , [gdt_data32] "n" (GDT_SEL_PM_DATA32)
        , [gdt_code16] "n" (GDT_SEL_PM_CODE16)
        , [gdt_data16] "n" (GDT_SEL_PM_DATA16)
        , [msr_efer] "n" (CPU_MSR_EFER)
        , [cr0_pg_bit] "n" (CPU_CR0_PG_BIT)
        , [cr0_wp_bit] "n" (CPU_CR0_WP_BIT)
        , [cr4_pae_bit] "n" (CPU_CR4_PAE_BIT)
        , [msr_efer_lme_bit] "n" (CPU_MSR_EFER_LME_BIT)
        , [msr_efer_nx_bit] "n" (CPU_MSR_EFER_NX_BIT)
        : "eax", "ecx", "edx", "esi", "edi", "memory"
    );
}