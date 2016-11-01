#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <unistd.h>


#define N           (10)

extern int errno;

int
main(int argc, char* argv[])
{
    char* tmp = NULL;
    char* buffer = malloc(N);
    static int nums = 1;

    errno = 0;
    while (getcwd(buffer, N*nums) == NULL)
    {
        if (errno == ERANGE)
        {
            tmp = realloc(buffer, ++nums * N);
            if (tmp == NULL)
            {
                fprintf(stderr, "memory failure\n");
                return EXIT_FAILURE;
            }
            buffer = tmp;
            fprintf(stderr, "errno = %d\n", errno);
            errno = 0;
        }
        else
        {
            fprintf(stderr, "errno = %d\n", errno);
        }
    }
    printf("buffer: %s\n", buffer);

    return EXIT_SUCCESS;
}
