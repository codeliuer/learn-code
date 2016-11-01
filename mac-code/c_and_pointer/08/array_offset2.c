#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#define LOW(i)          ((i) ? (2*(i)-1) : 0)
#define HIGH(i)         ((i) ? 2*(i) : 0)


static int 
array_offset(int* arrayinfo, ...)
{
    int i = 0;
    int s = 0;
    int loc = 0;
    int space = 1;
    va_list list;

    va_start(list, arrayinfo);
    for (i = 1; i <= arrayinfo[0]; i++)
    {
        s = va_arg(list, int);

        if (s < arrayinfo[LOW(i)] || s > arrayinfo[HIGH(i)])
        {
            va_end(list);

            return -1;
        }

        space *= (arrayinfo[HIGH(i-1)]-arrayinfo[LOW(i-1)]+1);
        loc += (s-arrayinfo[LOW(i)])*space;
    }
    va_end(list);

    return loc;
}

int
main(int argc, char* argv[])
{
    int arrayinfo[] = {3, 4, 6, 1, 5, -3, 3};

    printf("offset = %d\n", array_offset(arrayinfo, 4, 1, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 2, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 1, -1));
    printf("offset = %d\n", array_offset(arrayinfo, 5, 1, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 3, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 5, 3, -1));
    printf("offset = %d\n", array_offset(arrayinfo, 6, 1, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 1, -2));
    printf("offset = %d\n", array_offset(arrayinfo, 6, 5, 3));

    return EXIT_SUCCESS;
}
