#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>

#include <sys/resource.h>


extern int errno;


#ifdef RLIMIT_NOFILE
static void
resource_limit(int resource, long int values)
{
    struct rlimit rlim;

    errno = 0;
    if (getrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }

    printf("limit = %ld\n", rlim.rlim_cur);
    rlim.rlim_cur = values;
    errno = 0;
    if (setrlimit(resource, &rlim) < 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
}
#endif //RLIMIT_NOFILE


int
main(int argc, char* argv[])
{
    printf("open_max = %ld\n", sysconf(_SC_OPEN_MAX));
    printf("child_max = %ld\n", sysconf(_SC_CHILD_MAX));

#ifdef RLIMIT_NOFILE
    resource_limit(RLIMIT_NOFILE, 100);
#endif //RLIMIT_NOFILE

#ifdef RLIMIT_NPROC
    resource_limit(RLIMIT_NPROC, 100);
#endif //RLIMIT_NPROC

#ifdef RLIMIT_STACK
    resource_limit(RLIMIT_STACK, 100);
#endif //RLIMIT_STACK

    int i = 0;
    int stack[BUFSIZ] = {0};

    printf("open_max = %ld\n", sysconf(_SC_OPEN_MAX));
    printf("child_max = %ld\n", sysconf(_SC_CHILD_MAX));

    for (i = 0; i < sizeof(stack)/sizeof(stack[0]); i++)
    {
        stack[i] = i;
    }

    return EXIT_SUCCESS;
}
