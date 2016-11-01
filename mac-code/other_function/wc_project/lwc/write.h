/*
**	write a line number to user login 
**  directory file 
**  file is located in the learn-code
**  directory on a layer of directory
*/

#ifndef		__WC_WRITE_H__
#define		__WC_WRITE_H__


#include <stdio.h>

#include "basemacro.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


/*******************************************************************
 *                          macro                                  *
 *******************************************************************/
#define WC_SUCCESS              (0)
/*
** wc function error code
*/
#define WC_INVALID_PARAM        (1) //invalid parameter
#define WC_ACCESS               (2) //permission is denied
#define WC_DIR                  (3) //file operator failure

  
/*******************************************************************
 *                            type                                 *
 *******************************************************************/
typedef struct DATE_t
{
    int         year;
    int         mon;
    int         day;
    int         dayNums; //days from 2016-03-38
} DATE_t;


/*******************************************************************
 *                        extern function                          *
 *******************************************************************/
/*@@
** summary
**   get the current directory and all subdirectories 
** of all source code line number
** @pathname: the path name
** @plines: out-of-parameter
** return values:
**   success: 0
**   failure: error code
** Note: 
*/
WC_PUBLIC_API int
wc_get(const char* pathname, int* plines);


/*@@
** summary
**   write lines to file that of pfiles pointer
** @pathname: the path name
** @lines: lines of code
** return values:
**   success: 0
**   failure: error code
** Note: 
*/
WC_PUBLIC_API int 
wc_write(DATE_t* pdate, int lines);


/*@@
** summary
**   get numbers of days from 2016-03-28
** @pinfo: get date and days
** return values:
**   success: 0
**   failure: error code
** Note: the function always returns success
*/
WC_PUBLIC_API int 
wc_date(DATE_t* pinfo);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif	//__WC_WRITE_H__
