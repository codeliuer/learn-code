#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARR_ELE_NUM(arr)    (sizeof(arr)/sizeof(arr[0]))

#define SWAP(a, b)          {int t = a; a = b; b = t;}


static unsigned long total = 0;

static void
show(int* array, int num)
{
    int i = 0;

    total++;
    for (i = 0; i < num; i++)
    {
        printf(array[i] <= 9 ? "%d  " : "%c  ", array[i]);
    }
    printf("\n");
}

static void
whole_arrang(int* array, int start, int num)
{
    int i = 0;

    if (start == num)
    {
        show(array, num);
        return;
    }

    for (i = start; i < num; i++)
    {
        SWAP(array[start], array[i]);
        whole_arrang(array, start+1, num);
        SWAP(array[start], array[i]);
    }
}

int
main(int argc, char* argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 'a',};

    whole_arrang(arr, 0, ARR_ELE_NUM(arr));
    printf("total = %lu\n", total);

    return EXIT_SUCCESS;
}
