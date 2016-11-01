#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
    char buffer[] = "25.142.330,Smith,J,239-4123";

    /* Search string prefix */
    printf("%*.*lu\n", 3, 3, strspn(buffer, ".123456789"));

    /* complement */
    printf("%lu\n", strcspn(buffer, "\n\r\f\t\v"));

    return EXIT_SUCCESS;
}
