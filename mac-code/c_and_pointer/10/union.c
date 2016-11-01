#include <stdio.h>
#include <stdlib.h>
#include <string.h>


union 
{
    float   f;
    int     i;
} u;


int
main(int argc, char* argv[])
{
    u.f = 3.14;

    printf("%d\n", u.i);

    return EXIT_SUCCESS;
}
