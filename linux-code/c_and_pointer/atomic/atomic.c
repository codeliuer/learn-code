#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int mutex = 0;
    int lock = 0;
    int unlock = 1;
    int count = 0;

    __sync_bool_compare_and_swap(&mutex, lock, 1);
    count++;
    __sync_bool_compare_and_swap(&mutex, unlock, 1);

    printf("count = %d\n", count);

    return EXIT_SUCCESS;
}
