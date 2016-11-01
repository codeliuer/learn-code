#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    int var = 0;
    int array[] = {1, 2, 3, 4};

    printf("sizeof(var) = %lu, sizeof(&var) = %lu\n", sizeof(var), sizeof(&var));
    printf("sizeof(array) = %lu, sizeof(&array) = %lu\n", sizeof(array), sizeof(&array));

    return EXIT_SUCCESS;
}
