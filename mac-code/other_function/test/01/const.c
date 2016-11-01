#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int a = 2;


int
main(int argc, char* argv[])
{
    int* pa = (int *)&a;
    *pa = 3;
    printf("*pa = %d\n", *pa);

    switch (3)
    {
    case 1:
        break;
    case a:
        break;
    case 3:
        break;
    }

    return EXIT_SUCCESS;
}
