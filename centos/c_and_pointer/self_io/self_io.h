#ifndef __SELF_IO__
#define __SELF_IO__


#define printinfo(format, ...)      self_print(__FILE__, __func__, __LINE__, format, ##__VA_ARGS__)
#define fprintinfo(io, format, ...) self_fprint(__FILE__, __func__, __LINE__, io, format, ##__VA_ARGS__)


extern int printinfo(const char *format, ...);
extern int fprintinfo(FILE *stream, const char *format, ...);

#endif //__SELF_IO__
