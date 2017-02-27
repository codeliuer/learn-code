#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int count = 0;

    printf("%d\n", __sync_fetch_and_add(&count, 1));
    printf("count = %d\n", count);
    printf("%d\n", __sync_add_and_fetch(&count, 100));
    printf("count = %d\n", count);

    return EXIT_SUCCESS;
}
