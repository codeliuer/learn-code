#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* 
** plan a
*/
struct PHONE_NUM
{
    short   area;
    short   exchange;
    short   station;
};

struct LONG_DISTANCE_BILL
{
    short       month;
    short       day;
    short       year;
    int         time;
    struct PHONE_NUMBER called;
    struct PHONE_NUMBER calling;
    struct PHONE_NUMBER billed;
};


/*
** Scheme 2
*/
struct LONG_DISTANCE_BILL
{
    short       month;
    short       day;
    short       year;
    int         time;
    struct PHONE_NUMBER numbers[3];
};


int
main(int argc, char* argv[])
{

    return EXIT_SUCCESS;
}
