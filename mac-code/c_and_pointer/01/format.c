#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TEST
{
    char        *format;
    enum
    {
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
    };
    int         a[];
};


struct TEST test = {"liuwei", 3, 4, 5, 6,};


int
main(int argc, char* argv[])
{
    printf("%0*d\n", 3, 4);

    int i = 0;

    for (i = 0; i < FIVE; i++)
    {
        printf("%d\n",test.a[i]);
    }

    return EXIT_SUCCESS;
}
