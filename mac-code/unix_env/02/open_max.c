#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>


#if defined(OPEN_MAX)
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif  //OPEN_MAX

#define OPEN_MAX_GUESS          (256)


long 
open_max(void)
{
    if (openmax != 0)
    {
        return openmax;
    }

    errno = 0;
    if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
    {
        if (errno == 0)
        {
            openmax = OPEN_MAX_GUESS;
        }
        else
        {
            fprintf(stderr, "sysconf error for _SC_OPEN_MAX\n");
        }
    }

    return openmax;
}


int
main(int argc, char* argv[])
{
    printf("%ld\n", open_max());

    return EXIT_SUCCESS;
}
