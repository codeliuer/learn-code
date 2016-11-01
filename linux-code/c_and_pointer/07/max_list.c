#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


static int 
max_list(int first, ...)
{
    va_list arg;
    int value = 0;
    int max = first;

    va_start(arg, first);
    for (value=va_arg(arg, int); (value >= 0); value=va_arg(arg, int))
    {
        max = max > value ? max : value;
    }
    va_end(arg);

    return max;
}


int
main(int argc, char* argv[])
{
    printf("%d\n", max_list(1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 200, 111, 123, -1));

    return EXIT_SUCCESS;
}
