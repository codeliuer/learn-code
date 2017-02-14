#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>


#define read_lock(fd, whence, offset, len)          \
    lock_reg((fd), F_SETLK, F_RDLOCK, (offset), (whence), (len))
#define readw_lock(fd, whence, offset, len)         \
    lock_reg((fd), F_SETLKW, F_RDLOCK, (offset), (whence), (len))
#define write_lock(fd, whence, offset, len)         \
    lock_reg((fd, F_SETLK, F_WRLOCK, (offset), (whence), (len)))
#define writew_lock(fd, whence, offset, len)        \
    lock_reg((fd), F_SETLKW, F_WRLOCK, (offset), (whence), (len))
#define un_lock(fd, offset, whence, len)            \
    lock_reg((fd), F_SETLK, F_UNLCK, (offset), (whence), (len))


int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;

    lock.l_type = type;         /* F_RDLOCK, F_WRLOCK, F_UNLOCK */
    lock.l_whence = whence;     /* byte offset, relative to l_whence */
    lock.l_start = offset;      /* SEEK_SET, SEEK_CUR, SEEK_END */
    lock.l_len = len;           /* bytes (0 means to EOF) */
    lock.l_pid = getpid();

    return (fcntl(fd, F_SETLK, &lock));
}
