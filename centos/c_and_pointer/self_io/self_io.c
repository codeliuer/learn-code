#include <stdio.h>
#include <stdlib.h>


#define printinfo(format, ...)  self_print(__FILE__, __func__, __LINE__, format, ##__VA_ARGS__)


int self_print(const char *file, const char *func, int line, const char *format, ...)
{
}


int self_fprint()
{
}
