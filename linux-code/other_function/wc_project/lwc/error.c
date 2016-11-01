/*
** format output
*/

#include <stdio.h>
#include <stdarg.h>

#include "error.h"


/*******************************************************************
 *                          macro                                  *
********************************************************************/

/* color macro */
#define NONE                "\e[0m"
#define BLACK               "\e[0;30m"
#define L_BLACK             "\e[1;30"
#define RED                 "\e[0;31m"
#define L_RED               "\e[1;31m"
#define GREEN               "\e[0;32m"  
#define L_GREEN             "\e[1;32m"

#define BOLD                "\e[1m"
#define UNDERLINE           "\e[4m"
#define BLINK               "\e[5m"
#define REVERSE             "\e[7m"
#define HIDE                "\e[8m"
#define CLEAR               "\e[2J"

#define OUT                 (0)
#define IN                  (1)

#define UNUSED(x)           ((void)x)


/*******************************************************************
 *                          function                               *
********************************************************************/

WC_PUBLIC_API int
show(const char* file, const char* func, int line, const char* format, ...)
{
    int nbytes = 0;
    va_list list;

    UNUSED(func);
    UNUSED(file);
    UNUSED(line);
//    nbytes = printf(RED"%s/%s[%d]: "NONE, file, func, line);
    va_start(list, format);
    nbytes += vprintf(format, list);
    va_end(list);

    return nbytes;
}

WC_PUBLIC_API int
sshow(char* buffer, const char* format, ...)
{
    int nbytes = 0;
    va_list list;

    va_start(list, format);
    nbytes = vsprintf(buffer, format, list);
    va_end(list);

    return nbytes;
}


WC_PUBLIC_API int
fsnshow(char* buffer, size_t buflen, const char* format, ...)
{
    int nbytes = 0;
    va_list list;

    va_start(list, format);
    nbytes = vsnprintf(buffer, buflen, format, list);
    va_end(list);

    return nbytes;
}


WC_PUBLIC_API int
fshow(FILE* stream, const char* file, const char* func, int line, const char* format, ...)
{
    int flag = 0;
    int nbytes = 0;
    va_list list;

    if ((stream == stdout) || (stream == stderr))
    {
        flag = IN;
#ifdef DEBUG
        nbytes = fprintf(stream, RED"%s/%s[%d]: ", file, func, line);
#else
        nbytes = fprintf(stream, RED);
#endif
    }
    else
    {
        nbytes = fprintf(stream, "%s/%s[%d]: ", file, func, line);
    }
    va_start(list, format);
    nbytes += vfprintf(stream, format, list);
    va_end(list);

    if (flag == IN)
    {
        nbytes += fprintf(stream, NONE);
    }

    return nbytes;
}
