#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BIGINT          (0xFFFFFFFFFFFFFFFFFFFF)


int
main(int argc, char* argv[])
{
    printf("%ld\n", sizeof(BIGINT));
    printf("%ld\n", sizeof(long long int));

    return EXIT_SUCCESS;
}
