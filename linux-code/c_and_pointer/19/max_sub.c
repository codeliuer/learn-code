#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUMS(arr)           (sizeof(arr)/sizeof(arr[0]))


typedef struct NODE
{
    int     x;
    int     y;
    int     sum;
} NODE;

static void show(NODE *pnode)
{
    printf("start = %d, end = %d, sum = %d\n", pnode->x, pnode->y, pnode->sum);
}

static void max_sub(int *arr, size_t len)
{
    int i = 0;
    int thissum = 0;
    int maxsum = 0;

    for (i = 0; i < len; i++)
    {
        thissum += arr[i];
        if (thissum > maxsum)
        {
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
        }
    }
    printf("maxsum = %d\n", maxsum);
}

static void show_arr(int *arr, int start, int end)
{
    int i = 0;

    for (i = start; i < end; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int arr[] = {-2, 11, 8, -4, -1, 16, 5, 0,};

    show_arr(arr, 0, NUMS(arr));
    max_sub(arr, NUMS(arr));

    return EXIT_SUCCESS;
}
