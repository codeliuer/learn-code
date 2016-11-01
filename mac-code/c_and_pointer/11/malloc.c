#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    void* ptr = malloc(0);

    printf("ptr = %p\n", ptr);

    free(ptr);

    ptr = malloc(sizeof(int));

//    free(ptr+1);
    free(ptr);

    return EXIT_SUCCESS;
}
