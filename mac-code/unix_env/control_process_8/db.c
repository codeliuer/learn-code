#include <stdio.h>
#include <stdarg.h>

#include <db.h>


int
debug_print(const char *filename, int line, const char *format, ...)
{
	int retnum = 0;
	va_list arg;

	retnum += printf("%s(%d)  ", filename, line);
		
	va_start(arg, format);
	retnum += vprintf(format, arg);
	va_end(arg);

	return retnum;
}


int 
debug_fprint(FILE *stream, const char *filename, int line, const char *format, ...)
{
	int retnum = 0;
	va_list arg;

	retnum += fprintf(stream, "%s(%d)  ", filename, line);
		
	va_start(arg, format);
	retnum += vfprintf(stream, format, arg);
	va_end(arg);

	return retnum;
}
