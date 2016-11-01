#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>


int
main(int argc, char* argv[])
{
    struct rlimit rlim = {0};

    errno = 0;
    if (getrlimit(RLIMIT_NOFILE, &rlim) < 0)
    {
        fprintf(stderr, "errno = %d\n", errno);
    }
    printf("soft limit = %ld\n", rlim.rlim_cur);
    printf("hard limit = %ld\n", rlim.rlim_max);

    errno = 0;
    if (getrlimit(RLIMIT_AS, &rlim) < 0)
    {
        fprintf(stderr, "errno = %d\n", errno);
    }
    printf("soft limit = %ld\n", rlim.rlim_cur);
    printf("hard limit = %ld\n", rlim.rlim_max);

    printf("%d bytes\n", getpagesize());

    return EXIT_SUCCESS;
}
