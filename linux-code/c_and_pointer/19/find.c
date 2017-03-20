#include <stdio.h>
#include <stdlib.h>


static int arr[7][7] = 
{
    {100, 100, 100, 100, 100, 100, 100}
    {100, 1, 2, 3, 4, 5, 100,},
    {100, 2, 3, 4, 5, 6, 100,},
    {100, 3, 4, 5, 6, 7, 100,},
    {100, 4, 5, 6, 7, 8, 100,},
    {100, 5, 6, 7, 8, 9, 100,},
    {100, 100, 100, 100, 100, 100, 100}
}


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
    }

    return EXIT_SUCCESS;
}
