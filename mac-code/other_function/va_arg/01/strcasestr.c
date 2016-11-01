#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    /*
    ** strcasestr()  ignores the case of both arguments
    */
    printf("%s\n", strcasestr("1234567890qwASDFGHJKLMNBxcc", "QWasd"));

    return EXIT_SUCCESS;
}
