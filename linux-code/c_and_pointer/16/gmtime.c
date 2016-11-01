#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int
main(int argc, char* argv[])
{
    time_t t = time(NULL);

    printf("%s", asctime(gmtime(&t)));
    printf("%s", asctime(localtime(&t)));

    return EXIT_SUCCESS;
}
