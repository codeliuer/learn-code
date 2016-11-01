/*
** wc_project header file 
** command: lwc ~/learn-code
** author: john(codeliuer)
** date: 2016-07-23
*/

#ifndef     __COMMON_H__
#define     __COMMON_H__


#include "basemacro.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


/*******************************************************************
 *                          macro                                  *
 *******************************************************************/

/* lwc command main function */
#define wc_main             common


/*******************************************************************
 *                          function                               *
 *******************************************************************/

/*@@
** summary
**   lwc command main function
** @argc: the number of parameter
** @argv: string array
** return value:
**   success: 0
**   failure: error code
** Note:
*/
WC_PUBLIC_API int
wc_main(int argc, char* argv[]);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif  //__WC_MAIN_H__
