#include <stdio.h>
#include <stdlib.h>


#define printinfo(format, ...)  self_print(__FILE__, __func__, __LINE__, format, ##__VA_ARGS)


int self_print()
{
}


int self_fprint()
{
}
