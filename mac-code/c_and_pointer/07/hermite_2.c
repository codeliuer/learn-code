#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int 
hermite(int n, int x)
{
    int i = 0;
    int sum = 0;
    int old_value = 1;
    int new_value = 2*x;

    for (i = 2; i <= n; i++)
    {
        sum = 2*x*new_value - 2*(i-1)*old_value;

        old_value = new_value;
        new_value = sum;
    }

    return sum;
}


int
main(int argc, char* argv[])
{
    printf("%d\n", hermite(3, 2));

    return EXIT_SUCCESS;
}
