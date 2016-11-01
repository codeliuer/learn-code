#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
   printf("%ld\n", sysconf(_SC_NZERO));

    return EXIT_SUCCESS;
}
