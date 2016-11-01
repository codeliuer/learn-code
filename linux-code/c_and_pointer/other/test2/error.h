/*
** the header file of error
*/

#ifndef     __ERROR_H__
#define     __ERROR_H__

#include <stdio.h>


#define l_print(format, ...)                                \
                err_print(__FILE__, __LINE__, format, ##__VA_ARGS__)
#define l_fprint(stream, format, ...)                       \
                err_fprint(stream, __FILE__, __LINE__, format, ##__VA_ARGS__)


extern int
err_print(const char* filename, int lines, const char* format, ...);
extern int
err_fprint(FILE* stream, const char* filename, int lines, const char* format, ...);


#endif  //__ERROR_H__
