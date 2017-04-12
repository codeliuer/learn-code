#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


static int *bucket[10] = {0};


int main(int argc, char *argv[])
{
    int i = 0;
    int nums = 0;
    int *arr = NULL;

    scanf("%d", &nums);

    arr = (int *)malloc(sizeof(*arr) * nums);
    if (arr == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    for (i = 0; i < nums; i++)
    {
        arr[i] = rand()%10000;
    }

    return EXIT_SUCCESS;
}
