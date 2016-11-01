/*
** wc_project
** This is statistical directory of lines of code program, 
** contain statistics date, the amount of code that every 
** day line number, the total amount of code directory
** and the average daily amount of code
*/

#include <unistd.h>

#include "common.h"
#include "write.h"
#include "error.h"


/*******************************************************************
 *                         extern function                         *
 *******************************************************************/

/********************************************************************
 * summary
 *   lwc command main function
 * @argc: the number of (char*)
 * @argv: char** type
 * return values:
 *   success: 0
 *   failure: error code
 * Note: the main function of lwc instruction
********************************************************************/

WC_PUBLIC_API int 
wc_main(int argc, char* argv[])
{
    int lines = 0;
    DATE_t date = {0};
    char abs_path[BUFSIZ] = "";

    if (argc < 2)
    {
        wc_fprint(stderr, "Usage: lwc dir\n");
        return WC_INVALID_PARAM;
    }

    while (--argc)
    {
        wc_date(&date);
        if (wc_get(argv[argc], &lines) != WC_SUCCESS)
        {
            continue;
        }
    //    wc_print("lines = %d\n", lines);
        wc_write(&date, lines);
    }

    return WC_SUCCESS;
}
