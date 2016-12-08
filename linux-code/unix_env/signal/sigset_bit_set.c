#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>

#include <unistd.h>


#define SET             (0)
#define CLEAR           (1)


#define sigaddset       self_sigaddset
#define sigdelset       self_sigdelset
#define sigemptyset     self_sigemptyset
#define sigfillset      self_sigfillset
#define sigismember     self_sigismember


/* <signal.h> usually defines NSIG to include signal number 0 */
// #define SIGBAD(signo)   ((signo) <= 0 || (signo >= NSIG))


#define setbit(data, n)     __makebits(data, NSIG, n, SET)
#define clearbit(data, n)   __makebits(data, NSIG, n, CLEAR)


extern int errno;


static int __makebits(void *data, int totals, int nbits, int tag)
{
    int i = 0;
    int j = 0;
    char *pch = (char *)data;

    if (nbits > totals || nbits <= 0)
    {
        return -1;
    }

    i = (nbits-1) / CHAR_BIT;
    j = (nbits-1) % CHAR_BIT;

    pch[i] = ((tag == SET) ? (1 << j) : (~(1 << j)));

    return 0;
}


int sigaddset(sigset_t *set, int signo)
{
    if (setbit(set, signo))
    {
        errno = EINVAL;
        return -1;
    }

    return 0;
}

int sigdelset(sigset_t *set, int signo)
{
    if (clearbit(set, signo))
    {
        errno = EINVAL;
        return -1;
    }

    return 0;
}


int sigfillset(sigset_t *set)
{
    memset(set, 0xFF, sizeof(*set));

    return 0;
}


int sigemptyset(sigset_t *set)
{
    memset(set, 0, sizeof(*set));

    return 0;
}


int sigismember(sigset_t *set, sigset_t signo)
{
    sigset_t val = 0;

    memcpy(&val, set, sizeof(*set));
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
