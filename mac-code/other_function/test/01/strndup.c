/*
** test strndup and strdup
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    char string[] = "1234567890";
    char *pstring = strndup(string, 5);

    printf("%s\n", pstring);
    free(pstring);

    return EXIT_SUCCESS;
}
