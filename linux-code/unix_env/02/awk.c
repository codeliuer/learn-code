#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>


static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);


int
main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out <dirname>");
        exit(EXIT_FAILURE);
    }

#ifdef ARG_MAX
    printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX+0);
#else
    printf("no sysbol for ARG_MAX\n");
#endif  //ARG_MAX

#ifdef _SC_ARG_MAX
    pr_sysconf("ARG_MAX = ", _SC_ARG_MAX);
#else
    printf("no symbol for _SC_ARG_MAX");
#endif  //_SC_ARg_MAX

    /* 
    ** similar processing for all the rest of the sysconf symbol ...
    */
#ifdef MAX_CANON
    printf("MAX_CANON defined to be %ld\n", (long)MAX_CANON+0);
#else
    printf("no symbol for MAX_CANON\n");
#endif  //MAX_CANON

#ifdef _PC_MAX_CANON
    pr_pathconf("MAX_CANON =", argv[1], _PC_MAX_CANON);
#else
    printf("no symbol for _PC_MAX_CANON\n");
#endif  //_PC_MAX_CANON

    return EXIT_SUCCESS;
}


static void
pr_sysconf(char* mesg, int name)
{
    long val;

    fputs(mesg, stdout);
    errno = 0;
    if ((val = sysconf(name)) < 0)
    {
        if (errno != 0)
        {
            fputs(" (not suported)\n", stdout);
        }
        else
        {
            fprintf(stderr, "sysconf error\n");
        }
    }
    else
    {
        printf(" %ld\n", val);
    }
}


static void
pr_pathconf(char* mesg, char* path, int name)
{
    long val;

    fputs(mesg, stdout);
    errno = 0;
    if ((val = pathconf(path, name)) < 0)
    {
        if (errno != 0)
        {
            fputs(" (not supported)\n", stdout);
        }
        else
        {
            fprintf(stderr, "pathconf error, path = %s\n", path);
        }
    }
    else
    {
        printf(" %ld\n", val);
    }
}
