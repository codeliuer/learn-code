#include <stdio.h>
#include <stdlib.h>


static void perm(int *arr, size_t size)
{
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6,};

    perm(arr, sizeof(arr)/sizeof(arr[0]));

    return EXIT_SUCCESS;
}
