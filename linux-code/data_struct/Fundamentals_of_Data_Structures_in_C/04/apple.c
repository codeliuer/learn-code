#include <stdio.h>
#include <stdlib.h>


static int 
get_apples(int n)
{
    int k = n;
    int sum = 1;

    while (--n)
    {
        sum = k * sum + 1;
    }

    return sum;
}


int 
main(int argc, char *argv[])
{
    int n = 0;

    while (scanf("%d", &n) == 1)
    {
        printf("number = %d\n", get_apples(n));
    }

    return EXIT_SUCCESS;
}
