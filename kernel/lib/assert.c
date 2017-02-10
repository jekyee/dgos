#include "assert.h"
#include "printk.h"

void assert_failed(char const *expr,
                   char const *msg,
                   char const *file,
                   int line)
{
    printdbg("\n** ASSERT FAILED: %s(%d): %s %s\n",
           file, line, expr, msg ? msg : "");
}

