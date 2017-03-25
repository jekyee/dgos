#include "debug.h"

static write_debug_str_handler_t write_debug_str_vec;

void write_debug_str_set_handler(write_debug_str_handler_t handler)
{
    write_debug_str_vec = handler;
}

int write_debug_str(char const *str, intptr_t len)
{
    return write_debug_str_vec(str, len);
}
