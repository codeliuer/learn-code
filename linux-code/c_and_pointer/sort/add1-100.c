/***********************************************************************
 * from start to end to add
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>


static void clear(void)
{
    // clear stdin
    scanf("%*[^\n]");
    scanf("%*c");
    // fflush(stdin);
}


static void enter(int *data, const char *str)
{
    while ((printf("%s", str), scanf("%d", data)) != 1)
    {
        clear();
    }

    clear();
}


static int adds(int start, int end)
{
    int i = 0;
    int sum = 0;

    for (i = start; i <= end; i++)
    {
        sum += i;
    }

    return sum;
}


int main(int argc, char *argv[])
{
    int start = 0;
    int end = 0;
    int sum = 0;

    for (;;)
    {
        enter(&start, "enter start digit = ");
        enter(&end, "enter over digit = ");

        sum = adds(start, end);

        printf("sum = %d\n", sum);
    }

    return EXIT_SUCCESS;
}
