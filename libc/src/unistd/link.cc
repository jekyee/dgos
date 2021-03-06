#include <unistd.h>
#include <sys/syscall.h>
#include <sys/syscall_num.h>
#include <sys/types.h>
#include <errno.h>

int link(char const *target, char const *link)
{
    long status = syscall2(uintptr_t(target), uintptr_t(link), SYS_link);

    if (status >= 0)
        return status;

    errno = -status;

    return -1;
}
