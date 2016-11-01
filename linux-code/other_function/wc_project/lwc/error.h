/*
** wc_project module format print 
*/

#ifndef     __ERROR_H__
#define     __ERROR_H__


#include <stdio.h>

#include "basemacro.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define FILE_FUNC_LINE                  __FILE__, __func__, __LINE__


#define wc_print(format, ...)           show(FILE_FUNC_LINE, format, ##__VA_ARGS__)
//#define wc_sprint(buffer, format, ...)  sshow(buffer, format, ##__VA_ARGS__)
#define wc_sprint(buffer, format, ...)  sprintf(buffer, format, ##__VA_ARGS__)
#define wc_snprint(buffer, buflen, format, ...) \
    fsnshow(buffer, buflen, format, ##__VA_ARGS__)

#define wc_fprint(stream, format, ...)  fshow(stream, FILE_FUNC_LINE, format, ##__VA_ARGS__)


WC_PUBLIC_API int 
show(const char* file, const char* func, int line, const char* format, ...);

WC_PUBLIC_API int 
fshow(FILE* stream, const char* file, const char* func, int line, const char* format, ...);

WC_PUBLIC_API int
fsnshow(char* buffer, size_t buflen, const char* format, ...);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif  //__ERROR_H__
