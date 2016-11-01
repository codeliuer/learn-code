#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
    const char *ptr = "123456789";
    const char *tmp = ptr;

    while (*tmp)
    {
        printf("%c\r\n", *tmp);
        tmp++;
    }

    return EXIT_SUCCESS;
}
