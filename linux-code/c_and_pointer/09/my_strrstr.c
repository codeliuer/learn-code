#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static const char*
my_strrstr(const char* string, const char* seg)
{
    const char* ptr = NULL;
    const char* ret = NULL;

    for (ptr=strstr(string, seg); ptr; ptr=strstr(ptr+1, seg))
    {
        ret = ptr;
    }

    return ret;
}


int
main(int argc, char* argv[])
{
    const char string[] = "12345678909876543121233321232123212321232123asd";

    printf("%s\n", my_strrstr(string, "123"));

    return EXIT_SUCCESS;
}
