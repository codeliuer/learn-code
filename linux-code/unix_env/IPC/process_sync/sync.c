#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define UNUSED(x)           ((void)x)


static int parentfd[2], childfd[2];

void TELL_WAIT(void)
{
    if (pipe(parentfd) < 0 || pipe(childfd) < 0)
    {
        perror("pipe failure: ");
        return;
    }
}

void WAIT_PARENT(void)
{
    char token;

    read(parentfd[0], &token, 1);
}

void WAIT_CHILD(void)
{
    char token;

    read(childfd[0], &token, 1);
}

void TELL_PARENT(pid_t pid)
{
    UNUSED(pid);

    write(childfdp1[1], "t", 1);
}

void TELL_CHILD(pid_t pid)
{
}
