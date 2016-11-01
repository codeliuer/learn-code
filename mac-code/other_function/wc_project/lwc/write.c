/*
** put the date, numbers of rows, the total number of rows    
** and the average number of rows written .${DIR} file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "write.h"
#include "error.h"


/*******************************************************************
 *                         macro                                   *
 *******************************************************************/

#define INTERVAL                (2)     /* format control */

/*
** start date code statistics
*/
#define WT_START_DATE           "2016-03-28"

#define RWXRWXRWX               (S_IRWXU | S_IRWXG | S_IRWXO)

#define WCSTRCMP(dest, R, src)  (strcmp(dest, src) R 0)
#define WCSTRNCMP(dest, R, src) (strncmp(dest, src, strlen(src)) R 0)


/*******************************************************************
 *                         type                                    *
 *******************************************************************/

typedef unsigned char   bool;

typedef struct FORMAT
{
    int             width;      /* format print width */
    char*           format;     /* format control */
    char*           name;       /* the row name */
} FORMAT_t;

/* the info that all write to the file */
typedef struct INFO
{
    DATE_t*         pdate;      /* time and days */
    int             newlines;   /* now total lines */
    int             line;       /* previous total lines */
    double          aver;

#define ENUM_TIME   (0)
#define ENUM_DAYS   (1)
#define ENUM_TOTAL  (2)
#define ENUM_LINE   (3)
#define ENUM_AVER   (4)

    FORMAT_t        format[];
} INFO_t;


/*******************************************************************
 *                         macro                                   *
 *******************************************************************/

static INFO_t ginfo = 
    {
        NULL, 0, 0, 0,                                  /* base member */
    /*  width           format              name */     /* fixleble array member initializer */
        10,             "%-*s",             "time",
        5,              "%-*d",             "days",
        10,             "%-*d",             "total",
        5,              "%-*d",             "line",
        10,             "%-*lf",            "average",
    };


/*******************************************************************
 *                         internal interface                      *
 *******************************************************************/

/*
** separate name
*/
static void
parse_name(char* buffer, const char* pathname)
{
#define OUT         (0)
#define IN          (1)

    int flag = OUT;
    const char* ptr = NULL;

    while (*pathname != NUL)
    {
        if ((flag == OUT) && (*pathname != '/'))
        {
            flag = IN;
            ptr = pathname;
        }
        else if (*pathname == '/')
        {
            flag = OUT;
        }

        pathname++;
    }

#undef OUT
#undef IN

    while ((*ptr != NUL) && (*ptr != '/'))
    {
        *buffer++ = *ptr++;   
    }
    *buffer = NUL;
}

/*
** get file name that to read data and save data
*/
static void
get_name(char* buffer, const char* pathname)
{
    if (WCSTRCMP(pathname, !=, "/"))
    {
        parse_name(buffer, pathname);
    }
    else
    {
        strcpy(buffer, "root");
    }
}

/*
** identification file data
*/
static void
ident_file(const char* pathname, char* filename)
{
    char buffer[CONSTANT_128] = "";

    /* hidden file */
    strcpy(filename, ".");

    get_name(buffer, pathname);
    strcat(filename, buffer);
//    wc_print("%s\n", filename);
}

static bool
isfile(const char* filename)
{
    struct stat st;

    /* do not follow symblic link */
    if (lstat(filename, &st) < 0)
    {
        return false;
    }

    return (S_ISREG(st.st_mode)) ? true : false;
}

static FILE * 
create_file(const char* filename)
{
    mode_t old;
    FILE* pfile = NULL;

    old = umask(RWXRWXRWX);
    if (access(filename, F_OK) < 0)
    {
        pfile = fopen(filename, "w+");
    }
    else
    {
        if (isfile(filename))
        {
            pfile = fopen(filename, "r+");
        }
    }
    /* restore the scene */
    umask(old);

    return pfile;
}

static FILE *
init_file(void)
{
    char abs_path[PATH_MAX] = "";
    char filename[CONSTANT_32] = "";

    getcwd(abs_path, sizeof(abs_path));
    ident_file(abs_path, filename);
//    wc_print("%s\n", filename);
    return create_file(filename);
}

static void
date_to_string(char* date, size_t len, DATE_t* pdate)
{
    snprintf(date, len, "%4d-%02d-%02d", pdate->year, pdate->mon, pdate->day);
}

static int 
get_index(FORMAT_t* pformat, const char* name)
{
    int i = 0;

    while (WCSTRCMP(pformat[i].name, !=, name))
    {
        i++;
    }

    return i;
}

static const char *
loop_char(const char** buffer)
{
    //wc_print("buffer: %s", *buffer);
    while (isspace(**buffer))
    {
        (*buffer)++;
    }

    while (!isspace(**buffer))
    {
        (*buffer)++;
    }
    
    return *buffer;
}

static int 
get_line(const char* buffer, const char* name)
{
    int i = 0;
    int index = 0;
    const char* ptr = NULL;

    index = get_index(ginfo.format, name);
    for (i = 0; i < index; i++)
    {
        ptr = loop_char(&buffer);
    }

    return atoi(ptr);
}

static void 
get_oldinfo(FILE* pfile, DATE_t* pdate, int* pold, int* plines)
{
    long offset = 0;
    char date[CONSTANT_32] = "";
    char buffer[CONSTANT_128] = "";

    date_to_string(date, sizeof(date), pdate);
    offset = ftell(pfile);
    while (fgets(buffer, sizeof(buffer), pfile) != NULL)
    {
	//wc_print("%s", buffer);
	//wc_print("date: %s\n", date);
        if (WCSTRNCMP(buffer, ==, date))
        {
            *pold = get_line(buffer, "total");
            *plines = get_line(buffer, "line");

            fseek(pfile, offset, SEEK_SET);

            return;
        }
        else
        {
            *pold = get_line(buffer, "total");
        }

        offset = ftell(pfile);
    }
}

static void
init_info(INFO_t* pinfo, DATE_t* pdate, int newtotal, int oldtotal, int lines)
{
    pinfo->pdate = pdate;
    pinfo->newlines = newtotal;
    pinfo->line = newtotal - oldtotal + lines;
    pinfo->aver = (double)newtotal / pinfo->pdate->dayNums;
}

#define cache(type)                                                 \
    static char*                                                    \
    cache_##type(char* ptr, const type* pdata, int index)           \
{                                                                   \
    int off = 0;                                                    \
    int width = 0;                                                  \
    char* format = NULL;                                            \
                                                                    \
    width = ginfo.format[index].width;                              \
    format = ginfo.format[index].format;                            \
                                                                    \
    if (WCSTRCMP(#type, ==, "char"))                                \
    {                                                               \
        off = wc_sprint(ptr, format, width, pdata);                 \
    }                                                               \
    else                                                            \
    {                                                               \
        off = wc_sprint(ptr, format, width, *pdata);                \
    }                                                               \
                                                                    \
    return (ptr+off);                                               \
}

cache(char)
cache(int)
cache(double)

#define cache_days(ptr, data)       cache_int(ptr, data, ENUM_DAYS)
#define cache_total(ptr, total)     cache_int(ptr, total, ENUM_TOTAL)
#define cache_line(ptr, line)       cache_int(ptr, line, ENUM_LINE)

#define cache_aver(ptr, aver)       cache_double(ptr, aver, ENUM_AVER)

static char*
cache_date(char* ptr, DATE_t* pdate)
{
    char date[CONSTANT_32] = "";

    date_to_string(date,  sizeof(date), pdate);

    return cache_char(ptr, date, ENUM_TIME);
}

static char*
loop_space(char* ptr, int val)
{
    while (val--)
    {
        *ptr++ = ' ';
    }

    return ptr;
}

static void
cache_buffer(char* ptr, INFO_t* pinfo)
{
    ptr = cache_date(ptr, pinfo->pdate);
    ptr = loop_space(ptr, INTERVAL);   

    ptr = cache_days(ptr, &pinfo->pdate->dayNums);
    ptr = loop_space(ptr, INTERVAL);

    ptr = cache_total(ptr, &pinfo->newlines);
    ptr = loop_space(ptr, INTERVAL);

    ptr = cache_line(ptr, &pinfo->line);
    ptr = loop_space(ptr, INTERVAL);

    ptr = cache_aver(ptr, &pinfo->aver);
}

static void
write_date(FILE* pfile, INFO_t* pinfo)
{
    char buffer[CONSTANT_128] = "";

    //wc_print("enter\n");
    cache_buffer(buffer, pinfo);
    wc_print("%s\n", buffer);
    fputs(buffer, pfile);
    fputs("\n", pfile);
}

static void
uninit_file(FILE* pfile)
{
    fclose(pfile);
}

/*******************************************************************
 *                         extern interface                        *
 *******************************************************************/

/********************************************************************
 * summary
 *   write lines to .file that of pfiles pointer
 * @pfile: file infomation pointer
 * @lines: lines of code
 * return values:
 *   success: 0
 *   failure: error code
 * Note: 
********************************************************************/

WC_PUBLIC_API int 
wc_write(DATE_t* pdate, int newlines)
{
    int oldtotal = 0;
    int line = 0;

    FILE* pfile = init_file();
    if (pfile == NULL)
    {
        wc_fprint(stderr, "file init failure\n");
        return WC_DIR;
    }
    get_oldinfo(pfile, pdate, &oldtotal, &line);

    init_info(&ginfo, pdate, newlines, oldtotal, line);
    write_date(pfile, &ginfo);

    uninit_file(pfile);

    return WC_SUCCESS;
}
