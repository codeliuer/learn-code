#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    unsigned char arr[] = {0x01, 0x02, 0x03, 0x04};

    printf("%ld\n", sizeof(arr));

    return EXIT_SUCCESS;
}
