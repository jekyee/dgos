#include "debug.h"
#include "string.h"
#include "utf.h"

static void e9out(void const *data, size_t len)
{
    __asm__ __volatile__ (
        "rep outsb\n\t"
        "out %%al,%%dx\n\t"
        :
        : "S" (data), "c" (len), "d" (0xe9), "a" ('\n')
        : "memory"
    );
}

void debug_out(char const *s, ptrdiff_t len)
{
    if (len < 0)
        len = strlen(s);
    e9out(s, len);
}

void debug_out(char16_t const *s, ptrdiff_t len)
{

    if (len < 0)
        len = strlen(s);

    char16_t const *end = s + len;

    // Allocate worst case UTF-8 output buffer
    char16_t const *in = s;
    char *buf = (char*)__builtin_alloca(len*4+1);
    char *out = buf;
    ptrdiff_t enc_len = 0;
    while (in < end) {
        char32_t codepoint = utf16_to_ucs4(in, &in);
        enc_len += ucs4_to_utf8(out + enc_len, codepoint);
    }
    e9out(buf, enc_len);
}
