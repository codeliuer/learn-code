#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int
main(int argc, char* argv[])
{
    time_t t1 = time(NULL);

    sleep(1);

    time_t t2 = time(NULL);

    printf("%lf\n", difftime(t2, t1));

    return EXIT_SUCCESS;
}
