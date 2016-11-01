/*
** deal with error
*/

#include <stdio.h>
#include <stdarg.h>

#include "error.h"


int
err_print(const char* filename, int lines, const char* format, ...)
{
    int nbytes = 0;
    va_list list;

    printf("%s[%d]: ", filename, lines);
    va_start(list, format);
    nbytes = vprintf(format, list);
    va_end(list);

    return nbytes;
}


int
err_fprint(FILE* stream, const char* filename, int lines, const char* format, ...)
{
    int nbytes = 0;
    va_list list;

    printf("%s[%d]: ", filename, lines);
    va_start(list, format);
    nbytes = vfprintf(stream, format, list);
    va_end(list);

    return nbytes;
}
