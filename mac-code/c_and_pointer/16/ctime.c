#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int
main(int argc, char* argv[])
{
    time_t t = time(NULL);

    printf("%s", ctime(&t));

    return EXIT_SUCCESS;
}
