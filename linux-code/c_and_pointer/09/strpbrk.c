#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    const char string[] = "Hello there, honey!";
    char* ans = NULL;

    ans = strpbrk(string, "aeiou");

    printf("string = %p, ans = %p\n", string, ans);

    return EXIT_SUCCESS;
}
