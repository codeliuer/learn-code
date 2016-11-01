#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define array_element(arr)      (sizeof(arr)/sizeof(arr[0]))


static int arr[] = {1, 2, 3, 4, 5, 6, 7};
static int brr[] = {0, 0, 0, 0};


static void
show(void)
{
    int i = 0;

    for (i = 0; i < array_element(brr); i++)
    {
        printf("%d  ", arr[brr[i]]);
    }
    printf("\n");
}

static void
combine(int num, int ai)
{
    int i = 0;

    if (num == array_element(brr))
    {
        show();
        return;
    }

    for (; ai < array_element(arr); ai++)
    {
        brr[num] = ai;
        combine(num+1, ai+1);
    }
}


int
main(int argc, char* argv[])
{
    combine(0, 0);

    return EXIT_SUCCESS;
}
