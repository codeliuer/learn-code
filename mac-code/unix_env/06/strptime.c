/*
** strptime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

int
main(void)
{
    struct tm tm;
    char buf[255];

    memset(&tm, 0, sizeof(struct tm));
    strptime("2001-11-12 18:31:01", "%Y-%m-%d %H:%M:%S", &tm);
    printf("second = %d\n", tm.tm_sec);
    printf("minute = %d\n", tm.tm_min);
    printf("hour   = %d\n", tm.tm_hour);
    printf("day    = %d\n", tm.tm_mday);
    printf("month  = %d\n", tm.tm_mon);
    printf("year   = %d\n", tm.tm_year);
    strftime(buf, sizeof(buf), "%d %b %Y %H:%M", &tm);
    puts(buf);

    exit(EXIT_SUCCESS);
}

