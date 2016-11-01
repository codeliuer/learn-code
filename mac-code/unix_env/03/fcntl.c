#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char* argv[])
{
    int val = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out <descriptor>\n");
        return EXIT_FAILURE;
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL)) < 0)
    {
        fprintf(stderr, "val = %d\n", val);
        return EXIT_FAILURE;
    }

    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        printf("unkown access mode");
        break;
    }

    if (val & O_APPEND)
    {
        printf(", append");
    }
    else if (val & O_NONBLOCK)
    {
        printf(", nonblocking");
    }
    else if (val & O_SYNC)
    {
        printf(", synchronous writes");
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
    {
        printf(", synchronous write");
    }
#endif  //_POSIX_C_SOURCE

    putchar('\n');

    return EXIT_SUCCESS;
}
