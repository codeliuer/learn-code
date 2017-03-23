#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUMS(arr)           (sizeof(arr)/sizeof(arr[0]))


static void compare(int *pa, int nums1, int *pb, int nums2, int max)
{
    int i = nums1-1;
    int j = nums2-1;

    if (pa == NULL || pb == NULL || nums2 == 0)
    {
        return;
    }

    while (i >= 0 && j >= 0)
    {
        if (pa[i] > pb[j])
        {
            pa[--max] = pa[i--];
        }
        else
        {
            pa[--max] = pb[j--];
        }
    }
}

static void show(int *pa, int nums)
{
    int i = 0;

    while (i < nums)
    {
        printf("%d-- ", pa[i]);
        i++;
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int a1[8] = {4, 6, 8, 10,};
    int a2[] = {5, 7, 9, 11,};

    compare(a1, 4, a2, NUMS(a2), NUMS(a1));
    show(a1, NUMS(a1));

    return EXIT_SUCCESS;
}
