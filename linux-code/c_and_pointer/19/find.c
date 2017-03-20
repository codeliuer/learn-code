#include <stdio.h>
#include <stdlib.h>


static int arr[5][5] = 
{
    {1, 2, 3, 4, 5,},
    {2, 3, 4, 5, 6,},
    {3, 4, 5, 6, 7,},
    {4, 5, 6, 7, 8,},
    {5, 6, 7, 8, 9,},
};


int main(int rgc, char *argv[])
{
    int n = 0;
    int i = 1;
    int j = 1;

    n = 8;

    while (i != 5 || j != 5)
    {
        if (arr[i][j] == n)
        {
            printf("find number (%d, %d)\n", i, j);
        }
        else if (arr[i][j] > n)
        {
            i += 1;
        }
        else
        {
            j += 1;
        }
    }

    if (arr[i][j] == n)
    {
        printf("find number (%d, %d)\n", i, j);
    }
    else
    {
        printf("not find number, n = %d\n", n);
    }

    return EXIT_SUCCESS;
}
