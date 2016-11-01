#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char * argv[])
{
    printf("%ld\n", sysconf(_SC_ARG_MAX));

    return EXIT_SUCCESS;
}
