#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long int value = 0;
    long int &qvalue = value;
    long int var = 0;

    printf("&value = %p\n", &value);
    printf("&var   = %p\n", &var);

    return EXIT_SUCCESS;
}
