#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


#define SET_FL              (0)
#define CLEAR_FL            (1)


typedef int (*FP_callback_t)(int, int);


static int com_set_fl(int base, int flags);
static int com_clear_fl(int base, int flags); 


static FP_callback_t cb[] = {com_set_fl, com_clear_fl};


static void
file_flags(int fd, int flags, FP_callback_t callback)
{
    int base;

    errno = 0;
    base = fcntl(fd, F_GETFL, 0);
    if (base < 0)
    {
        perror("fcntl, get fl");
        return;
    }

    /* turn/off on flags */
    base = callback(base, flags);
    if (fcntl(fd, F_SETFL, base) < 0)
    {
        perror("fcntl, set fl");
        return;
    }
}


void 
set_fl(int fd, int flags)
{
    file_flags(fd, flags, com_set_fl);
}

void
clr_fl(int fd, int flags)
{
    file_flags(fd, flags, com_clear_fl);
}


static int
com_set_fl(int base, int flags)
{
    return (base |= flags);
}


static int 
com_clear_fl(int base, int flags)
{
    return (base &= ~flags);
}
