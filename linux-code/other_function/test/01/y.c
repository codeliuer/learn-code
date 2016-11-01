#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char *argv[])
{
    int x = 1;
    int y = ~x;

    printf("%d\n", y);

    float f = 3.3;
    double d = 4.4;

    if ((d+f)-d == f)
    {
        printf("equal\n");
    }

    return EXIT_SUCCESS;
}
