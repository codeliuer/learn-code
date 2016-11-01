#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#define INT             (0)
#define DOUBLE          (1)
#define CHAR            (2)
#define STRING          (3)

#define DEBUG           (1)

#define print_char      putchar


#define print(value, TYPE)                                                  \
    static int print##_##TYPE(TYPE value)                                   \
{                                                                           \
    char string[BUFSIZ] = "";                                               \
                                                                            \
    sprintf(string, (strcmp(#TYPE, "double")==0) ? "%lf" : "%d", value);    \
                                                                            \
    return print_string(string);                                            \
}


static int 
print_string(const char* string)
{
    int byte = 0;

    while (*string)
    {
        putchar(*string++);
        byte++;
    }

    return byte;
}

print(value, int);
print(value, double);

static int 
print_type(void* arg, int type)
{
    int byte = 0;

    switch (type)
    {
    case CHAR:
        print_char(*(char *)arg);
        byte++;
        break;
    case INT:
        byte += print_int(*(int *)arg);
        break;
    case DOUBLE:
        byte += print_double(*(double *)arg);
        break;
    case STRING:
        byte += print_string((char *)arg);
        break;
    }

    return byte;
}

static int 
myprintf(const char* format, ...)
{
    va_list arg;
    char* ptmp = NULL;
    int itmp = 0;
    double ftmp = 0.0;
    int retvalue = 0;

    va_start(arg, format);
    while (*format)
    {
        if (*format != '%')
        {
            retvalue++;
            print_type((void *)format++, CHAR);
            continue;
        }

        switch (*++format)
        {
        case 'c':           case 'd':
            itmp = va_arg(arg, int);
            retvalue += print_type((void *)&itmp, (*format== 'c') ? CHAR : INT);
            break;
        case 's':
            ptmp = va_arg(arg, char *);
            retvalue += print_type((void *)ptmp, STRING);
            break;
        case 'f':
            ftmp = va_arg(arg, double);
            retvalue += print_type((void *)&ftmp, DOUBLE);
            break;
        case '%':
            itmp = '%';
            ftmp += print_type((void *)&itmp, CHAR);
            break;
        default:
            retvalue += print_type((void *)"nonsupport\n", STRING);
            break;
        }
        format++;
    }
    va_end(arg);

    return retvalue;
}

int
main(int argc, char* argv[])
{
    (void)myprintf("line = %d, %f\n", __LINE__, 3.14);

    return EXIT_SUCCESS;
}
