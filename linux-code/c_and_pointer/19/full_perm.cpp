#include <stdio.h>
#include <stdlib.h>


static void print(int *arr, int end)
{
    int i = 0;

    for (i = 0; i <= end; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}


static void perm(int *arr, size_t start, size_t end)
{
    int i = 0;

    if (start == end)
    {
        print(arr, end);
    }
    else
    {
        for (i = start; i <= end; i++)
        {
            swap(arr, i, start);
            perm(arr, i+1, end);
            swap(arr, i, start);
        }
    }
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6,};

    perm(arr, 0, sizeof(arr)/sizeof(arr[0])-1);

    return EXIT_SUCCESS;
}
