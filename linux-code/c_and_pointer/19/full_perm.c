#include <stdio.h>
#include <stdlib.h>

static int num = 0;

static void print(int *arr, int end)
{
    int i = 0;

    for (i = 0; i <= end; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

static void swap(int *arr, int start, int end)
{
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
}

static void perm(int *arr, size_t start, size_t end)
{
    int i = 0;

    if (start == end)
    {
        num += 1;
        print(arr, end);
    }
    else
    {
        for (i = start; i <= end; i++)
        {
            swap(arr, i, start);
            perm(arr, start+1, end);
            swap(arr, i, start);
        }
    }
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6,};

    perm(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    printf("num = %d\n", num);

    return EXIT_SUCCESS;
}
