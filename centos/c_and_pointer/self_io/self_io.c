#include <stdio.h>
#include <stdlib.h>


#define printinfo(format, ...)      self_print(__FILE__, __func__, __LINE__, format, ##__VA_ARGS__)
#define fprintinfo(io, format, ...) self_fprint(__FILE__, __func__, __LINE__, io, format, ##__VA_ARGS__)


int self_print(const char *file, const char *func, int line, const char *format, ...)
{
    va_list ap;

    vprintf("%s(%s)[%d]", file, func, line);

    va_start(ap, format);
    vprintf(format, ap);
    va_end(ap);
}


int self_fprint(const char *file, const char *func, int line, FILE *stream, const char *format, ...)
{
}
