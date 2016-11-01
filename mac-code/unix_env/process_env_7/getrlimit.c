/*
** resource limit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/resource.h>


#define doit(name)          pr_limits(#name, name)


static void pr_limits(char *, int);


int
main(int argc, char* argv[])
{
#if defined(RLIMIT_AS)
    doit(RLIMIT_AS);
#endif //RLIMIT_AS

    doit(RLIMIT_CORE);
    doit(RLIMIT_CPU);
    doit(RLIMIT_DATA);
    doit(RLIMIT_FSIZE);
#if defined(RLIMIT_MEMLOCK)
    doit(RLIMIT_MEMLOCK);
#endif //RLIMIT_MEMLOCK

#ifdef RLIMIT_MSGQUEUE
    doit(RLIMIT_MSGQUEUE);
#endif  //RLIMIT_MSGQUEUE

#ifdef RLIMIT_NICE
    doit(RLIMIT_NICE);
#endif  //RLIMIT_NICE

    doit(RLIMIT_NOFILE);

#ifdef RLIMIT_NPROC
    doit(RLIMIT_NPROC);
#endif  //RLIMIT_NPROC

#ifdef RLIMIT_NPTS
    doit(RLIMIT_NPTS);
#endif  //RLIMIT_NPTS

#ifdef RLIMIT_RSS
    doit(RLIMIT_RSS);
#endif //RLIMIT_RSS

#ifdef RLIMIT_SBSIZE
    doit(RLIMIT_SBSIZE);
#endif  //RLIMIT_SBSIZE

#ifdef RLIMIT_SIGPENDING
    doit(RLIMIT_SIGPENDING);
#endif //RLIMIT_SIGPENDING

#ifdef RLIMIT_STACK
    doit(RLIMIT_STACK);
#endif  //RLIMIT_STACK

#ifdef RLIMIT_SWAP
    doit(RLIMIT_SWAP);
#endif //RLIMIT_SWAP

#ifdef RLIMIT_VMEM
    doit(RLIMIT_VMEM);
#endif //RLIMIT_VMEM

    return EXIT_SUCCESS;
}


static void 
pr_limits(char *name, int resource)
{
    struct rlimit limit;
    unsigned long long lim;

    if (getrlimit(resource, &limit) < 0)
    {
        fprintf(stderr, "getrlimit error for %s", name);
    }
    printf("%-20s ", name);
    if (limit.rlim_cur == RLIM_INFINITY)
    {
        printf("(infinity) ");
    }
    else
    {
        lim = limit.rlim_cur;
        printf("%10lld ", lim);
    }

    if (limit.rlim_max == RLIM_INFINITY)
    {
        printf("(infinity) ");
    }
    else
    {
        lim = limit.rlim_max;
        printf("%10lld ", lim);
    }
    putchar((int)'\n');
}
