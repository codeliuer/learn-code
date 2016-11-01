#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    int a = 100;
    void* ptr = &a;

    printf("ptr = %p\n", ptr);

    return EXIT_SUCCESS;
}
