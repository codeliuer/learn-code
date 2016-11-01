/*
** All statistics specified directory specified format file lines of code
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <assert.h>

#include <unistd.h>
#include <dirent.h>

#include "stack.h"
#include "memory.h"


#define FALSE                           (0)
#define TRUE                            (1)

#define STRCMP(dest, R, src)            (strcmp(dest, src) R 0)
#define CMP_POSTFIX(dest, len, R, src)  (STRCMP(dest+len-strlen(src), R, src))
#define DEALWITH_NULL(v)                                    \
    do{                                                     \
        if ((v) == NULL)                                    \
        {                                                   \
            fprintf(stderr, "%s: %s[%d] %s\n", __FILE__,    \
                    __FUNCTION__, __LINE__, #v);            \
            /* exit(EXIT_FAILURE); */                       \
        }                                                   \
    } while (0)


typedef unsigned char       bool;


static bool
istargetfile(const char* name)
{
    int len = strlen(name);

/*    if (STRCMP(name+len-2, ==, ".c") || STRCMP(name+len-2, ==, ".h")
        || STRCMP(name+len-2, ==, ".s")
        || STRCMP(name+len-4, ==, ".cpp") || STRCMP(name+len-4, ==, ".txt"))*/
    if (CMP_POSTFIX(name, len, ==, ".c") || CMP_POSTFIX(name, len, ==, ".h") || CMP_POSTFIX(name, len, ==, ".s")
        || CMP_POSTFIX(name, len, ==, "sh") || CMP_POSTFIX(name, len, ==, "cpp") || CMP_POSTFIX(name, len, ==, ".txt"))
    {
        return TRUE;
    }

    return FALSE;
}

static unsigned long
file_line(const char* filename)
{
    unsigned long sum = 0;
    char string[BUFSIZ] = "";
    FILE* fp = NULL;

    DEALWITH_NULL(fp = fopen(filename, "r"));
    while (fgets(string, sizeof(string), fp))
    {
        if (string[strlen(string)-1] == '\n')
        {
            sum++;
        }
    }

    return sum;
}

static void
merme(char* pathname, char* dirname)
{
    strcat(pathname, "/");
    strcat(pathname, dirname);
}

static unsigned long
all_file_line(const char* dirname)
{
    unsigned long sum = 0;
    DIR* dir = NULL;
    struct dirent* dirent = NULL;
    char* openmax = NULL;
    size_t dirmaxlen = PATH_MAX;
	printf("PATH_MAX = %d\n", PATH_MAX);

    for (push(dirname); (dirname = pop()) != NULL; )
    {
        chdir(dirname);
        DEALWITH_NULL(dir = opendir(dirname));
        while ((dirent = readdir(dir)))
        {
            if ((/*dirent->d_namlen == 1 && */STRCMP(dirent->d_name, ==, "."))
                || (/*dirent->d_namlen == 2 && */STRCMP(dirent->d_name, ==, "..")))
            {
                continue;
            }

            if (dirent->d_type == DT_DIR)
            {
                openmax = New_Array(char, dirmaxlen);
                merme(getcwd(openmax, dirmaxlen), dirent->d_name);
                push(openmax);
            }
            else if ((dirent->d_type == DT_REG) && istargetfile(dirent->d_name))
            {
                sum += file_line(dirent->d_name);
            }
        }
        closedir(dir);
    }

    return sum;
}


#define ULONG_LEN               (20)
#define GITLOGFILE              "~/gitline.log"

static void
output_file(unsigned long nlines)
{
    char* pstring = NULL;
    FILE* pfile = NULL;
    char msg[BUFSIZ] = "";

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    sprintf(msg, "%04d-%02d-%02d %02d:%02d:%02d line:  %lu\n", tm->tm_year+1900,
            tm->tm_mon+1,  tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, nlines);
    printf("%s", msg);
    assert(pfile = fopen(GITLOGFILE,  access(GITLOGFILE, F_OK) ? "w+" : "a+"));
    fwrite(msg, sizeof(char), strlen(msg), pfile);
    fclose(pfile);
}

int
main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./execfile absolute pathname(true: ~/learn-code error: ./learn-code)\n");
        exit(EXIT_FAILURE);
    }

    output_file(all_file_line(argv[1]));

    return EXIT_SUCCESS;
}
