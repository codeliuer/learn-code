/*
** strftime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int
main(int argc, char* argv[])
{
    time_t t;
    struct tm *tmp = NULL;
    char buf1[16] = "";
    char buf2[64] = "";
    struct tm tm;

    time(&t);
    tmp = localtime(&t);

    if (strftime(buf1, sizeof(buf1), "time and date: %r, %a %b %d, %Y", tmp) == 0)
    {
        printf("buffer length 16 is too small\n");
    }
    else
    {
        printf("%s\n", buf1);
    }

    if (strftime(buf2, sizeof(buf2), "%Y-%m-%d %H:%M:%S", tmp) == 0)
    {
        printf("buffer length 16 is too small\n");
    }
    else
    {
        printf("%s\n", buf2);
    }

    printf("%s\n", buf2);
    strptime(buf2, "%Y-%m-%d %H:%M:%S", &tm);
    printf("second   = %d\n", tm.tm_sec);
    printf("minute   = %d\n", tm.tm_min);
    printf("hour     = %d\n", tm.tm_hour);
    printf("day      = %d\n", tm.tm_mday);
    printf("month    = %d\n", tm.tm_mon);
    printf("year     = %d\n", tm.tm_year);
    printf("weekday  = %d\n", tm.tm_wday);
    printf("yearday  = %d\n", tm.tm_yday);
    printf("daylight = %d\n", tm.tm_isdst);

    return EXIT_SUCCESS;
}
