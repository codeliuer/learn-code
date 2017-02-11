#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5,};
    int *ptr = arr;

    *(ptr++) += 100;

    printf("%d, %d\n", *ptr, *(++ptr));

    return EXIT_SUCCESS;
}
