#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/resource.h>


#define SIZEMAX                 (1000)


#define RLIMIT_AS_CUR           (10000000)


extern int errno;


#ifdef RLIMIT_AS
static void
set_as_resource(int tag)
{
    struct rlimit rlim;

    if (getrlimit(tag, &rlim) < 0)
    {
        fprintf(stderr, "get resource limit failure\n");
        return;
    }

    rlim.rlim_cur = RLIMIT_AS_CUR;
    if (setrlimit(tag, &rlim) < 0)
    {
        fprintf(stderr, "set resource limit failure\n");
        return;
    }
}
#endif //RLIMIT_AS


int
main(int argc, char* argv[])
{
#ifdef RLIMIT_AS
    void *ptr = NULL;

    errno = 0;
    set_as_resource(RLIMIT_AS);

    printf("errno = %d\n", errno);
    ptr = malloc(SIZEMAX);
    printf("%p\n", ptr);
    printf("errno = %d\n", errno);
    perror("memory: ");
    
    ptr = sbrk(SIZEMAX);
    if (ptr == NULL)
    {
        fprintf(stderr, "resource limited\n");
        return EXIT_FAILURE;
    }
    printf("%p\n", ptr);
//    perror("memory");

#endif //RLIMIT_AS
    return EXIT_SUCCESS;
}
