#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define print(x, format)        printf(#x " = " #format, x)


int
main(int argc, char* argv[])
{
    printf("%d\n", sysconf(_POSIX_CLOCKRES_MIN));
    printf("%d\n", CHARCLASS_NAME_MAX);
    printf("%d\n", COLL_WEIGHTS_MAX);
    printf("%d\n", LINE_MAX);
    printf("%d\n", NGROUPS_MAX);
    printf("%d\n", RE_DUP_MAX);

    printf("%ld\n", sysconf(_POSIX_ARG_MAX));
    printf("%ld\n", sysconf(_POSIX_CHILD_MAX));
    printf("%ld\n", sysconf(_POSIX_DELAYTIMER_MAX));
    printf("%ld\n", sysconf(_POSIX_HOST_NAME_MAX));
    printf("%ld\n", sysconf(_POSIX_LINK_MAX));

    printf("%ld\n", sysconf(_POSIX_CLK_TCK));

    return EXIT_SUCCESS;
}
