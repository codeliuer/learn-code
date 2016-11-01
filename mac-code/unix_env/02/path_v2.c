#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>


#if defined(PATH_MAX)
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif  //PATH_MAX


static long posix_version = 0;
static long xsi_version = 0;


#define PATH_MAX_GUESS      (1024)

void *
path_alloc(size_t * psize)
{
    void* ptr = NULL;

    if (*psize == NULL)
    {
        fprintf(stderr, "parameter invalid\n");
        return NULL;
    }

    if (posix_version == 0)
    {
        posix_version = sysconf(_SC_VERSION);
    }

    if (xsi_version == 0)
    {
        xsi_version = sysconf(_SC_XOPEN_VERSION);
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
                fprintf(stderr, "error for _PC_PATH_MAX\n");
            }
        }
        else
        {
            pathmax++;
        }
    }

    if ((posix_version < 200112L) && (xsi_version < 4))
    {
        *psize = pathmax+1;
    }
    else
    {
        *psize = pathmax;
    }

    if ((ptr = malloc(*psize)) == NULL)
    {
        fprintf(stderr, "malloc error for pathname\n");
        return NULL;
    }

    return ptr;
}


int
main(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}
