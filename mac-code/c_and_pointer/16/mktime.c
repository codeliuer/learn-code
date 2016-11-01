#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int
main(int argc, char* argv[])
{
    struct tm tm;
    time_t t = time(NULL);

    localtime_r(&t, &tm);
    tm.tm_yday = 0;
    tm.tm_wday = 0;

    mktime(&tm);

    printf("%d\n", tm.tm_yday);
    printf("%d\n", tm.tm_wday);
    printf("%d\n", tm.tm_isdst);

    return EXIT_SUCCESS;
}
