#include <stdio.h>
#include <stdlib.h>
#include <string.h>


union
{
    int         a;
    float       b;
    char        c[4];
}  x = 
    /* 
    ** Joint variables can be initialized, but the initialization
    ** must be joint type of the first members, and it must be 
    ** located inside the braces 
    */
    {
        5.33,
    };


int
main(int argc, char* argv[])
{
    printf("x.b = %d\n", x.a);

    return EXIT_SUCCESS;
}
