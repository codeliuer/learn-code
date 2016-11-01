/*
** the time relation function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static void
delay(long int num)
{
    while (num--)
    {
        ;
    }
}

int
main(int argc, char* argv[])
{
    time_t t;
    struct tm tm;
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);
    printf("%ld\n", ts.tv_sec);
    printf("%ld\n", ts.tv_nsec);

//    delay(10000000000l);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    printf("%ld\n", ts.tv_sec);
    printf("%ld\n", ts.tv_nsec);

    clock_gettime(CLOCK_REALTIME, &ts);
    printf("%ld\n", ts.tv_sec);
    printf("%ld\n", ts.tv_nsec);

    printf("%s", ctime(&ts.tv_sec));
    
    time(&t);
    localtime_r(&t, &tm);
    printf("second   = %d\n", tm.tm_sec);
    printf("minute   = %d\n", tm.tm_min);
    printf("hour     = %d\n", tm.tm_hour);
    printf("day      = %d\n", tm.tm_mday);
    printf("month    = %d\n", tm.tm_mon);
    printf("year     = %d\n", tm.tm_year);
    printf("weekday  = %d\n", tm.tm_wday);
    printf("yearday  = %d\n", tm.tm_yday);
    printf("daylight = %d\n", tm.tm_isdst);

    gmtime_r(&t, &tm);
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
