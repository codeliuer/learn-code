#include <stdio.h>
#include <stdlib.h>


#define false           (0)
#define true            (1)


static int arr[5][5] = 
{
    {1, 2, 3, 4, 5,},
    {2, 3, 4, 5, 6,},
    {3, 4, 5, 6, 7,},
    {4, 5, 6, 7, 8,},
    {5, 6, 7, 10, 11,},
};


int main(int rgc, char *argv[])
{
    int i = 0;
    int j = 4;

    int n = 10;

    while (i < 5 && j >= 0)
    {
        if (arr[i][j] == n)
        {
            printf("(%d, %d)\n", i, j);
        }
        else if (arr[i][j] > n)
        {
        }
        else
        {
        }
    }

    return EXIT_SUCCESS;
}
