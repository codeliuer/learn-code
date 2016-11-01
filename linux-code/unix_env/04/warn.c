#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void 
test(void)
{
    printf("11111\n");

    (void)&test;
}


int
main(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}
