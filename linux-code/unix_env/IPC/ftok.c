#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <fcntl.h>


#define MIDFILE         "midfile"

static int saveid(int id)
{
    int fd = 0;
    ssize_t len = 0;
    char buffer[20] = "";

    fd = open(MIDFILE, O_CREAT|O_RDWR, 0666);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }

    sprintf(buffer, "%d", fd);
    len = strlen(buffer);
    if (write(fd, buffer, len) != len)
    {
        perror("write failure: ");
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int msgid;
    struct msgbuf msgbuf;

    msgid = msgget(IPC_PRIVATE, IPC_CREAT|0666);
    if (msgid < 0)
    {
        perror("msgget failure: ");
        return EXIT_FAILURE;
    }

    if (saveid(msgid) < 0)
    {
        fprintf(stderr, "saveid failure: \n");
        return EXIT_FAILURE;
    }

    msgbuf.mtype = 1;
    strcpy(msgbuf.mtext, "hello world!");
    if (msgsnd(msgid, &msgbuf, strlen(msgbuf.mtext), 0) < 0)

    return EXIT_SUCCESS;
}
