#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>


#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif  //PATH_MAX

static long posix_version = 0;
static long xsi_version = 0;

/* If PATH_MAX is indeterminate, no guarantee this is adequate */
#define PATH_MAX_GUESS          (1024)


char *
path_alloc(size_t *sizep)
{
    char* ptr = NULL;
    size_t size;

    if (posix_version == 0)
    {
        posix_version = sysconf(_SC_VERSION);
        printf("%ld\n", posix_version);
    }

    if (xsi_version == 0)
    {
        xsi_version = sysconf(_SC_XOPEN_VERSION);
        printf("xsi_version = %ld\n", xsi_version);
    }

    if (pathmax == 0)
    {
        errno = 0;
        if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
        {
            if (errno == 0)
            {
                pathmax = PATH_MAX_GUESS;
            }
            else
            {
                fprintf(stderr, "pathconf error for _PC_PATH_MAX\n");
            }
        }
    }
    else
    {
        pathmax++;
    }

    if ((posix_version < 200112L) && xsi_version < 4)
    { 
        size = pathmax + 1;
    }
    else
    {
        size = pathmax;
    }

    if ((ptr = malloc(size)) == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        exit(EXIT_FAILURE);
    }

    if (sizep != NULL)
    {
        *sizep = size;
    }

    return (ptr);
}


int
main(int argc, char* argv[])
{
    size_t len = 0;
    char* ptr = path_alloc(&len);
    printf("len = %lu\n", len);

    return EXIT_SUCCESS;
}
