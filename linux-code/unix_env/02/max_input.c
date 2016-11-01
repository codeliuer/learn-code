#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
    printf("%ld\n", pathconf("/dev/zero", _PC_MAX_INPUT));
    printf("%ld\n", pathconf("/dev/zero", _PC_MAX_CANON));

    return EXIT_SUCCESS;
}
