#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int ladder(int m)
{
    if (m == 1)
    {
        return 1;
    }
    else if (m == 2)
    {
        return 2;
    }

    return ladder(m-1) + ladder(m-2);
}

int main(int argc, char *argv[])
{
    int n = 10;

    printf("%d\n ", ladder(4));

    return EXIT_SUCCESS;
}
