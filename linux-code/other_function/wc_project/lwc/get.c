/*
** get the current directory and subdirectories of all
** source code line number
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "write.h"
#include "basemacro.h"
#include "error.h"


/*******************************************************************
 *                         macro                                   *
 *******************************************************************/

#ifndef true
#define true                            (1)
#endif //true

#ifndef false
#define false                           (0)
#endif //false

#ifndef NUL
#define NUL                             '\0'
#endif //NUL


#define WC_STRCMP(dest, R, src)        (strcmp(dest, src) R 0)

/* compare the suffix */
#define WC_SUFCMP(dest, R, src)        WC_STRCMP(dest+strlen(dest)-strlen(src), R, src)


/*******************************************************************
 *                         type                                    *
 *******************************************************************/

typedef int (*FPfunc)(const char*, int*);


/*******************************************************************
 *                         statement                               *
 *******************************************************************/

static int base_cond(const char* pathname, int* plines, FPfunc func);
static int get_lines(const char* pathname, int* plines);


/*******************************************************************
 *                         globaldata                              *
 *******************************************************************/

extern int errno;


/*******************************************************************
 *                          internal                               *
 *******************************************************************/

static int 
statistic_lines(int fd)
{
    int sum = 0;
    int i = 0;
    int n = 0;
    char buffer[BUFSIZ] = "";

    while ((n = read(fd, buffer, sizeof(buffer))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (buffer[i] == '\n')
            {
                sum++;
            }
        }
    }

    return sum;
}

static int 
code_lines(const char* filename)
{
    int n = 0;
    int fd = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        wc_fprint(stderr, "%s not be opened\n", filename);
        return 0;
    }

    n = statistic_lines(fd);

    close(fd);

    return n;
}

static int 
istargetfile(const char* filename)
{
    int symbol = 0;    /* the point number */
    const char* tmp = filename;

    while (*tmp != NUL)
    {
        if (*tmp == '.')
        {
            symbol++;
        }

        tmp++;
    }

    if ((symbol == 1)
        && (WC_SUFCMP(filename, ==, ".c") 
        || WC_SUFCMP(filename, ==, ".h")
        || WC_SUFCMP(filename, ==, ".sh")
        || WC_SUFCMP(filename, ==, ".cpp")))
    {
        return true;
    }

    return false;
}

static int 
statistic_code(DIR* pdir, int* plines)
{
    struct dirent* ent = NULL;

    while ((ent = readdir(pdir)) != NULL)
    {
        if (WC_STRCMP(ent->d_name, ==, ".") 
                || WC_STRCMP(ent->d_name, ==, ".."))
        {
            continue;
        }

        if (ent->d_type == DT_DIR)
        {
            base_cond(ent->d_name, plines, get_lines);
        }
        else if ((ent->d_type == DT_REG) && istargetfile(ent->d_name))
        {
            *plines += code_lines(ent->d_name);
//            wc_print("line = %d\n", *plines);
        }
    }

    return WC_SUCCESS;
}


static void
get_invalid_path(char* buf, size_t len, const char* pathname)
{
    getcwd(buf, len);
    if (buf[strlen(buf)-1] != '/')
    {
        strcat(buf, "/");
    }
    strcat(buf, pathname);
}


static int 
get_lines(const char* pathname, int* plines)
{
    DIR* dir = NULL;
    char buf[PATH_MAX] = "";

    dir = opendir(pathname);
    if (dir == NULL)
    {
        get_invalid_path(buf, sizeof(buf), pathname);
        wc_fprint(stderr, "error: %s: %s\n", buf, strerror(errno));
        return WC_DIR;
    }

    /* set current work directory of process */
    if (chdir(pathname) < 0)
    {
//        wc_fprint(stderr, "set current work directory failure: %s\n", pathname);
        return WC_ACCESS;
    }
//    wc_print("current directory: %s\n", pathname);

    statistic_code(dir, plines);

    closedir(dir);

    return WC_SUCCESS;
}


static int
base_cond(const char* pathname, int* plines, FPfunc func)
{
    char buffer[PATH_MAX+1] = "";

    /* save current work directory */
    getcwd(buffer, sizeof(buffer));

    func(pathname, plines);

    /* restore the current working directory */
    chdir(buffer);

	return WC_SUCCESS;
}


/*******************************************************************
 *                          extern                                 *
 *******************************************************************/

/********************************************************************
 * summary
 *   get the current direcoty and all subdirectories of all source
 *   code line number  
 * @pathname: the path name
 * @plines: out-of-parameter
 * return values:
 *   success: 0
 *   failure: error code
 * Note: 
********************************************************************/

WC_PUBLIC_API int 
wc_get(const char* pathname, int* plines)
{
    int retcode = 0;
    char abs_path[CONSTANT_256] = "";

    WC_CHECK_T2Ptr(pathname, plines);
   
    getcwd(abs_path, sizeof(abs_path));
    /* recursive descento */
    retcode = get_lines(pathname, plines);
    chdir(abs_path);
    if (retcode != WC_SUCCESS)
    {
//        wc_fprint(stderr, "get_lines exec failure\n");
        return retcode;
    }
    //wc_print("lines = %d\n", *plines);

    return WC_SUCCESS;
}


/*******************************************************************
 *                          test                                   *
 *******************************************************************/

//#define TEST_GET
#ifdef TEST_GET
int
main(int argc, char* argv[])
{
    int lines = 0;
    char current[PATH_MAX] = "";

    wc_get(argv[1], &lines);
    wc_print("lines = %d\n", lines);
    wc_print("current directory: %s\n", getcwd(current, sizeof(current)));

    return EXIT_SUCCESS;
}
#endif //TEST_GET
