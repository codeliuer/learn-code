#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int arr[4][4] = 
{
    {10, 5, 7, 4},
    {9, 11, 12, 6},
    {1, 2, 4, 9},
    {15, 1, 1, 2},
};

static void show(int a[4][4])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

static int min(int m, int n)
{
    return m>n ? n : m;
}

static void print_path(int arr[4][4], int m, int n)
{
    if (m == 0 && n == 0)
    {
        printf("(%d, %d)", i, j);
        return 
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int tmp[4][4] = {0};

    show(arr);
    printf("#######################\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 0 && j == 0)
            {
                tmp[0][0] = arr[0][0];
            }
            else if (i == 0)
            {
                tmp[0][j] = arr[0][j] + tmp[0][j-1];
            }
            else if (j == 0)
            {
                tmp[i][0] = arr[i][0] + tmp[i-1][0];
            }
            else 
            {
                tmp[i][j] = arr[i][j] + min(tmp[i-1][j], tmp[i][j-1]);
            }
        }
    }

    print_path(tmp, 3, 3);

    show(tmp);

    return EXIT_SUCCESS;
}
