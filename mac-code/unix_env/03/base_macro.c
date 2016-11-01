#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
    printf("OPEN_MAX = %ld\n", sysconf(_SC_OPEN_MAX));

    return EXIT_SUCCESS;
}
