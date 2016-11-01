#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#define LOW(i)              (2*(i)-1)
#define HIGH(i)             (2*(i))

static int 
array_offset(int* arrayinfo, ...)
{
    int i = 0;
    int s = 0;
    int loc = 0;
    va_list arg;

    va_start(arg, arrayinfo);
    for (i = 1; i <= arrayinfo[0]; i++)
    {
        s = va_arg(arg, int);

        if ((s < arrayinfo[LOW(i)]) || (s > arrayinfo[HIGH(i)]))
        {
            va_end(arg);
            return -1;
        }
        loc = loc * (arrayinfo[HIGH(i)]-arrayinfo[LOW(i)]+1) + (s-arrayinfo[LOW(i)]);
    }
    va_end(arg);

    return loc;
}


int
main(int argc, char* argv[])
{
    int arrayinfo[] = {3, 4, 6, 1, 5, -3, 3};

    printf("offset = %d\n", array_offset(arrayinfo, 4, 1, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 1, 3));
    printf("offset = %d\n", array_offset(arrayinfo, 5, 1, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 1, -2));
    printf("offset = %d\n", array_offset(arrayinfo, 4, 2, -3));
    printf("offset = %d\n", array_offset(arrayinfo, 6, 3, 1));

    return EXIT_SUCCESS;
}
