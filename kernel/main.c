
#include "cpu.h"
#include "mm.h"
#include "printk.h"
#include "halt.h"
#include "pci.h"
#include "legacy_keyboard.h"

int life_and_stuff = 42;

char kernel_stack[262144];

char buf[12];

extern void (*device_constructor_list[])(void);

__thread int tls_thing;
//__thread int tls_thing_2;
__thread int tls_initialized_thing = 42;
__thread int tls_initialized_thing_2 = 43;
//__thread char tls_buf[10] = {24};

void volatile *trick;

static __attribute__((constructor)) void start_me_up()
{
    tls_thing = 1;
    //tls_thing_2 = 23;
    tls_initialized_thing = 2;
    tls_initialized_thing_2 = 3;
    trick = &tls_initialized_thing;
}

static __attribute__((destructor)) void goin_down()
{
    //tls_thing = -22;
}

// Pull in the device constructors
// to cause them to be initialized
void (** volatile device_list)(void) = device_constructor_list;

#define TEST_FORMAT(f, t, v) \
    printk("Test %8s -> '" f \
    "' 99=%d\t\t", f, (t)v, 99)

int main()
{
    pci_init();
    keyb8042_init();

    while (1)
        halt();

    return 0;

    //uint64_t *crash = (void*)0xfeedfacebeef0000;
    //*crash = (uint64_t)0xfeedfeedfeedfeed;

    printk("Testing!\n");
    printk("Testing again!\n");
    for (int i = 0; i < 22; ++i)
        printk("... and again!\n");

    // Check length specifiers and correct va_arg usage
    TEST_FORMAT("%hhd", signed char, 42);
    TEST_FORMAT("%hd", short, 42);
    TEST_FORMAT("%d", int, 42);
    TEST_FORMAT("%ld", long, 42);
    TEST_FORMAT("%lld", long long, 42);
    //TEST_FORMAT("%jd", intmax_t, 42);
    //TEST_FORMAT("%zd", ssize_t, 42);
    //TEST_FORMAT("%td", ptrdiff_t, 42);

    // Min-width only
    TEST_FORMAT("%5d", int, 42);

    // Min-width and precision
    TEST_FORMAT("%5.4d", int, 42);

    // Min-width < precision
    TEST_FORMAT("%4.5d", int, 42);

    // Min-width character
    TEST_FORMAT("%5c", int, '!');

    // Min-width hex
    TEST_FORMAT("%5x", int, 42);

    // Min-width hex with leading zeros
    TEST_FORMAT("%05x", int, 42);

    // Min-width hex with precision
    TEST_FORMAT("%5.3x", int, 42);

    // Left justified string with min-width
    TEST_FORMAT("%-5s", char*, "LJ");

    // Min-width decimal negative
    TEST_FORMAT("%5d", int, -42);

    TEST_FORMAT("%-5d", int, -42);
    TEST_FORMAT("%+5d", int, -42);
    //TEST_FORMAT("%+5.4td", ptrdiff_t, 42);
    //TEST_FORMAT("%+5.4td", ptrdiff_t, -42);

    return 42;
}
