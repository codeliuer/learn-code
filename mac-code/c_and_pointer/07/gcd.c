#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int 
gcd(int n, int r)
{
    if (n <= 0 || r <= 0)
    {
        return 0;
    }

    if (n % r == 0)
    {
        return r;
    }
    else
    {
        return gcd(r, n%r);
    }
}


int
main(int argc, char* argv[])
{
    printf("%d\n", gcd(100, 15));

    return EXIT_SUCCESS;
}
