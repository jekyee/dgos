// THIS FILE IS AUTOMATICALLY GENERATED
// from /home/doug/code/dgos/src/kernel/arch/x86_64/cpu/perf_reg.bits

// CPU_MSR_PERFEVTSEL

#define CPU_MSR_PERFEVTSEL_HG_ONLY_BIT            40
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_BIT       32
#define CPU_MSR_PERFEVTSEL_CNT_MASK_BIT           24
#define CPU_MSR_PERFEVTSEL_INV_BIT                23
#define CPU_MSR_PERFEVTSEL_EN_BIT                 22
#define CPU_MSR_PERFEVTSEL_IRQ_BIT                20
#define CPU_MSR_PERFEVTSEL_EDGE_BIT               18
#define CPU_MSR_PERFEVTSEL_OS_BIT                 17
#define CPU_MSR_PERFEVTSEL_USR_BIT                16
#define CPU_MSR_PERFEVTSEL_UNIT_MASK_BIT          8
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_BIT       0

#define CPU_MSR_PERFEVTSEL_HG_ONLY_BITS           2
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_BITS      4
#define CPU_MSR_PERFEVTSEL_CNT_MASK_BITS          8
#define CPU_MSR_PERFEVTSEL_INV_BITS               1
#define CPU_MSR_PERFEVTSEL_EN_BITS                1
#define CPU_MSR_PERFEVTSEL_IRQ_BITS               1
#define CPU_MSR_PERFEVTSEL_EDGE_BITS              1
#define CPU_MSR_PERFEVTSEL_OS_BITS                1
#define CPU_MSR_PERFEVTSEL_USR_BITS               1
#define CPU_MSR_PERFEVTSEL_UNIT_MASK_BITS         8
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_BITS      8
#define CPU_MSR_PERFEVTSEL_HG_ONLY_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_HG_ONLY_BITS)-1)
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_BITS)-1)
#define CPU_MSR_PERFEVTSEL_CNT_MASK_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_CNT_MASK_BITS)-1)
#define CPU_MSR_PERFEVTSEL_INV_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_INV_BITS)-1)
#define CPU_MSR_PERFEVTSEL_EN_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_EN_BITS)-1)
#define CPU_MSR_PERFEVTSEL_IRQ_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_IRQ_BITS)-1)
#define CPU_MSR_PERFEVTSEL_EDGE_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_EDGE_BITS)-1)
#define CPU_MSR_PERFEVTSEL_OS_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_OS_BITS)-1)
#define CPU_MSR_PERFEVTSEL_USR_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_USR_BITS)-1)
#define CPU_MSR_PERFEVTSEL_UNIT_MASK_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_UNIT_MASK_BITS)-1)
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_MASK \
    ((1UL << CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_BITS)-1)

// Host/Guest only mask
#define CPU_MSR_PERFEVTSEL_HG_ONLY \
    (CPU_MSR_PERFEVTSEL_HG_ONLY_MASK << CPU_MSR_PERFEVTSEL_HG_ONLY_BIT)

// Event select bits 11:8
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4 \
    (CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_MASK \
    << CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_BIT)

// Counter mask
#define CPU_MSR_PERFEVTSEL_CNT_MASK \
    (CPU_MSR_PERFEVTSEL_CNT_MASK_MASK << CPU_MSR_PERFEVTSEL_CNT_MASK_BIT)

// Invert
#define CPU_MSR_PERFEVTSEL_INV \
    (CPU_MSR_PERFEVTSEL_INV_MASK << CPU_MSR_PERFEVTSEL_INV_BIT)

// Enable
#define CPU_MSR_PERFEVTSEL_EN \
    (CPU_MSR_PERFEVTSEL_EN_MASK << CPU_MSR_PERFEVTSEL_EN_BIT)

// IRQ enable
#define CPU_MSR_PERFEVTSEL_IRQ \
    (CPU_MSR_PERFEVTSEL_IRQ_MASK << CPU_MSR_PERFEVTSEL_IRQ_BIT)

// Edge detect
#define CPU_MSR_PERFEVTSEL_EDGE \
    (CPU_MSR_PERFEVTSEL_EDGE_MASK << CPU_MSR_PERFEVTSEL_EDGE_BIT)

// Kernel mode
#define CPU_MSR_PERFEVTSEL_OS \
    (CPU_MSR_PERFEVTSEL_OS_MASK << CPU_MSR_PERFEVTSEL_OS_BIT)

// User mode
#define CPU_MSR_PERFEVTSEL_USR \
    (CPU_MSR_PERFEVTSEL_USR_MASK << CPU_MSR_PERFEVTSEL_USR_BIT)

// Unit mask
#define CPU_MSR_PERFEVTSEL_UNIT_MASK \
    (CPU_MSR_PERFEVTSEL_UNIT_MASK_MASK << CPU_MSR_PERFEVTSEL_UNIT_MASK_BIT)

// Event select bits 7:0
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8 \
    (CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_MASK \
    << CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_BIT)

#define CPU_MSR_PERFEVTSEL_HG_ONLY_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_HG_ONLY_BIT)
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_BIT)
#define CPU_MSR_PERFEVTSEL_CNT_MASK_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_CNT_MASK_BIT)
#define CPU_MSR_PERFEVTSEL_INV_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_INV_BIT)
#define CPU_MSR_PERFEVTSEL_EN_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_EN_BIT)
#define CPU_MSR_PERFEVTSEL_IRQ_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_IRQ_BIT)
#define CPU_MSR_PERFEVTSEL_EDGE_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_EDGE_BIT)
#define CPU_MSR_PERFEVTSEL_OS_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_OS_BIT)
#define CPU_MSR_PERFEVTSEL_USR_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_USR_BIT)
#define CPU_MSR_PERFEVTSEL_UNIT_MASK_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_UNIT_MASK_BIT)
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_n(n) \
    (uint64_t(n) << CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_BIT)

#define CPU_MSR_PERFEVTSEL_HG_ONLY_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_HG_ONLY_BIT) & CPU_MSR_PERFEVTSEL_HG_ONLY_MASK)
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_BIT) \
    & CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_MASK)
#define CPU_MSR_PERFEVTSEL_CNT_MASK_GET(n)        (((n) \
    >> CPU_MSR_PERFEVTSEL_CNT_MASK_BIT) & CPU_MSR_PERFEVTSEL_CNT_MASK_MASK)
#define CPU_MSR_PERFEVTSEL_INV_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_INV_BIT) & CPU_MSR_PERFEVTSEL_INV_MASK)
#define CPU_MSR_PERFEVTSEL_EN_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_EN_BIT) & CPU_MSR_PERFEVTSEL_EN_MASK)
#define CPU_MSR_PERFEVTSEL_IRQ_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_IRQ_BIT) & CPU_MSR_PERFEVTSEL_IRQ_MASK)
#define CPU_MSR_PERFEVTSEL_EDGE_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_EDGE_BIT) & CPU_MSR_PERFEVTSEL_EDGE_MASK)
#define CPU_MSR_PERFEVTSEL_OS_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_OS_BIT) & CPU_MSR_PERFEVTSEL_OS_MASK)
#define CPU_MSR_PERFEVTSEL_USR_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_USR_BIT) & CPU_MSR_PERFEVTSEL_USR_MASK)
#define CPU_MSR_PERFEVTSEL_UNIT_MASK_GET(n)       (((n) \
    >> CPU_MSR_PERFEVTSEL_UNIT_MASK_BIT) & CPU_MSR_PERFEVTSEL_UNIT_MASK_MASK)
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_GET(n) \
    (((n) >> CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_BIT) \
    & CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_MASK)

#define CPU_MSR_PERFEVTSEL_HG_ONLY_SET(r,n)       ((r) \
    = ((r) & ~CPU_MSR_PERFEVTSEL_HG_ONLY) | CPU_MSR_PERFEVTSEL_HG_ONLY_n((n)))
#define CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_SET(r,n)  ((r) = ((r) & \
    ~CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4) | CPU_MSR_PERFEVTSEL_EVT_SEL_HI_4_n((n)))
#define CPU_MSR_PERFEVTSEL_CNT_MASK_SET(r,n)      ((r) = \
    ((r) & ~CPU_MSR_PERFEVTSEL_CNT_MASK) | CPU_MSR_PERFEVTSEL_CNT_MASK_n((n)))
#define CPU_MSR_PERFEVTSEL_INV_SET(r,n) \
    ((r) = ((r) & ~CPU_MSR_PERFEVTSEL_INV) | CPU_MSR_PERFEVTSEL_INV_n((n)))
#define CPU_MSR_PERFEVTSEL_EN_SET(r,n) \
    ((r) = ((r) & ~CPU_MSR_PERFEVTSEL_EN) | CPU_MSR_PERFEVTSEL_EN_n((n)))
#define CPU_MSR_PERFEVTSEL_IRQ_SET(r,n) \
    ((r) = ((r) & ~CPU_MSR_PERFEVTSEL_IRQ) | CPU_MSR_PERFEVTSEL_IRQ_n((n)))
#define CPU_MSR_PERFEVTSEL_EDGE_SET(r,n) \
    ((r) = ((r) & ~CPU_MSR_PERFEVTSEL_EDGE) | CPU_MSR_PERFEVTSEL_EDGE_n((n)))
#define CPU_MSR_PERFEVTSEL_OS_SET(r,n) \
    ((r) = ((r) & ~CPU_MSR_PERFEVTSEL_OS) | CPU_MSR_PERFEVTSEL_OS_n((n)))
#define CPU_MSR_PERFEVTSEL_USR_SET(r,n) \
    ((r) = ((r) & ~CPU_MSR_PERFEVTSEL_USR) | CPU_MSR_PERFEVTSEL_USR_n((n)))
#define CPU_MSR_PERFEVTSEL_UNIT_MASK_SET(r,n)     ((r) = ((r) \
    & ~CPU_MSR_PERFEVTSEL_UNIT_MASK) | CPU_MSR_PERFEVTSEL_UNIT_MASK_n((n)))
#define CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_SET(r,n)  ((r) = ((r) & \
    ~CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8) | CPU_MSR_PERFEVTSEL_EVT_SEL_LO_8_n((n)))

// CPU_MSR_PERFEVTSEL_HG_ONLY_ALL
#define CPU_MSR_PERFEVTSEL_HG_ONLY_ALL 0

// CPU_MSR_PERFEVTSEL_HG_ONLY_GUEST
#define CPU_MSR_PERFEVTSEL_HG_ONLY_GUEST 1

// CPU_MSR_PERFEVTSEL_HG_ONLY_HOST
#define CPU_MSR_PERFEVTSEL_HG_ONLY_HOST 2

// CPU_MSR_PERFEVTSEL_HG_ONLY_BOTH
#define CPU_MSR_PERFEVTSEL_HG_ONLY_BOTH 3

// CPU_MSR_PERFEVTSEL_BASE
#define CPU_MSR_PERFEVTSEL_BASE 0xC0010000

// CPU_MSR_PERFCTR_BASE
#define CPU_MSR_PERFCTR_BASE 0xC0010004

