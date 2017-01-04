#include <stdio.h>
#include <stdarg.h>

#include "self_io.h"


int self_print(const char *file, const char *func, int line, const char *format, ...)
{
    va_list ap;
    int bytes = 0;

    printf("%s(%s)[%d]: ", file, func, line);

    va_start(ap, format);
    bytes = vprintf(format, ap);
    va_end(ap);

    return bytes;
}


int self_fprint(const char *file, const char *func, int line, FILE *stream, const char *format, ...)
{
    va_list ap;
    int bytes = 0;

    fprintf(stream, "%s(%s)[%d]: ", file, func, line);

    va_start(ap, format);
    bytes = vfprintf(stream, format, ap);
    va_end(ap);

    return bytes;
}
