#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int* arr;
extern int pa[];


extern void print_extern(void);

int
main(int argc, char* argv[])
{
    printf("arr = %p, pa = %p\n", arr, pa);

    print_extern();

    return EXIT_SUCCESS;
}
