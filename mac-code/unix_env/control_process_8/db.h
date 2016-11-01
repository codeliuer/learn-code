/*
** myself debug infomation
*/

#ifndef		__DB_H__
#define		__DB_H__


#include <stdarg.h>


#define db_print(format, ...)			debug_print(__FILE__, __LINE__, format, ##__VA_ARGS__)
#define db_fprint(stream, format, ...)	debug_fprint(stream, __FILE__, __LINE__, format, ##__VA_ARGS__)


#endif	//__DB_H__
