#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
    printf("%ld\n", sysconf(_SC_OPEN_MAX));

    return EXIT_SUCCESS;
}
