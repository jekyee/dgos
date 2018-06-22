#include "halt.h"
#include "debug.h"

extern "C" _noreturn void panic(tchar const *s)
{
    debug_out(s, -1);

    for (;;)
        __asm__ __volatile__ ("hlt");
}
