#include <stdio.h>
#include <stdlib.h>
#include <string.h>


f(int s)
{
    return s+1;
}


func(int s)
{
}


int
main(int argc, char *argv[])
{
    int z, x = 5, y = -10, a = 4, b = 2;

    z =  x++ - --y * b / a;

    printf("%d\n", z);

    return EXIT_SUCCESS;
}
