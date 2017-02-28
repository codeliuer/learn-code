#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 0;

    d = __sync_bool_compare_and_swap(&a, b, c);
    printf("d = %d\n", d);

    return EXIT_SUCCESS;
}
