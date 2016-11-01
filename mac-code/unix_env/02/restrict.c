#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* compile through std=c99 */
static void
func(char* restrict* p)
{
    *p = "adfasdfsd";
}

int
main(int argc, char* argv[])
{
    char* p = NULL;

    func(&p);
    printf("%s\n", p ? p : "NULL");

    return EXIT_SUCCESS;
}
