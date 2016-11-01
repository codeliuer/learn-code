#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int 
max_people(int n)
{
    int i = 0;
    int sum = 0;
    int max = 0;
    int next = 0;
    int up = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &next);
        scanf("%d", &up);

        sum += up - next;
        if (sum > max)
        {
            max = sum;
        }
    }

    return max;
}


int
main(int argc, char *argv[])
{
    int n = 0;

    while (scanf("%d", &n) == 1)
    {
        printf("%d\n", max_people(n));
    }

    return EXIT_SUCCESS;
}
