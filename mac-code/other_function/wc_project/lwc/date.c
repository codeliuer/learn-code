/*
** get number of the day from 2016-03-28
*/

//#define DATE_DEBUG
#ifdef DATE_DEBUG
# include <stdio.h>
# include <stdlib.h>
#endif //DATE_DEBUG
#include <time.h>

#include "write.h"
#include "error.h"


/*******************************************************************
 *                          macro                                  *
 *******************************************************************/

#define MIN_TO_SEC              (60)
#define HUR_TO_MIN              (60)

#define DAY_TO_HUR              (24)

#define DAY_TO_SEC              (DAY_TO_HUR * HUR_TO_MIN * MIN_TO_SEC)


/*******************************************************************
 *                          type                                   *
 *******************************************************************/

typedef struct date_t
{
    int             year;
    int             mon;
    int             day;
} date_t;


/*******************************************************************
 *                          internal data                          *
 *******************************************************************/

/*
** the original time, is the time I start coding and statistics
*/
static date_t oldDate = {2016, 03, 28};


/*******************************************************************
 *                          internal func                          *
 *******************************************************************/

static void
get_old_time(time_t* pt, date_t* pDate)
{
    struct tm tm = {0};

    tm.tm_year = pDate->year-1900; //from 1900
    tm.tm_mon = pDate->mon-1; //0 - 11
    tm.tm_mday = pDate->day;

    *pt = mktime(&tm);
}


static int
total_days(time_t* cur, time_t* old)
{
    int days = (*cur - *old) / DAY_TO_SEC;

    if (((*cur-*old) % DAY_TO_SEC) != 0)
    {
        days++;
    }

    return days;
}


static int 
number_of_days(time_t* pt, date_t* poldt)
{
    time_t oldt;

    get_old_time(&oldt, poldt);
    return total_days(pt, &oldt);
}


/*******************************************************************
 *                          extern                                 *
 *******************************************************************/

/*******************************************************************
 * summary
 *   get numbers of days from 2016-03-28 and current date
 * @pinfo: date infomation
 * return values:
 *   success: 0
 *   failure: error code
 * Note: the function always returns success
********************************************************************/

WC_PUBLIC_API int 
wc_date(DATE_t *pinfo)
{
    time_t curt;
    struct tm tm = {0};

    WC_CHECK_O1Ptr(pinfo);

    time(&curt);
    localtime_r(&curt, &tm);

    pinfo->year = tm.tm_year+1900;
    pinfo->mon = tm.tm_mon+1;
    pinfo->day = tm.tm_mday;
    pinfo->dayNums = number_of_days(&curt, &oldDate);

//    wc_print("days = %d\n", pinfo->dayNums);

    return WC_SUCCESS;
}


/*******************************************************************
 *                          test                                   *
 *******************************************************************/

#if defined(DATE_DEBUG)
int
main(int argc, char* argv[])
{
    DATE_t days = {0};

    wc_date(&days);
    wc_print("%d-%02d-%02d numday = %d\n", days.year, 
            days.mon, days.day, days.dayNums);

    return EXIT_SUCCESS;
}
#endif //TEST_DEBUG
