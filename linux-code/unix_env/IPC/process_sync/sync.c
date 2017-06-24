#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


static int fd1[2], fd2[2];

int TELL_WAIT()
{
    if (pipe(fd1) < 0 || pipe(fd2) < 0)
    {
        perror("pipe failure: ");
    }
}

int WAIT_PARENT()
{
}

int WAIT_CHILD()
{
}

int TELL_PARENT()
{
}

int TELL_CHILD()
{
}
