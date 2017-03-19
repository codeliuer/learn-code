#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6,};

    perm(arr, sizeof(arr)/sizeof(arr[0]));

    return EXIT_SUCCESS;
}
