#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


#define MIDFILE         "midfile"

struct msgbuf 
{
    long mtype;
    char mtext[20];
};

static int fetch(void)
{
    int fd = 0;
    char buffer[BUFSIZ] = "";

    fd = open(MIDFILE, O_RDONLY);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }

    if (read(fd, buffer, sizeof(buffer)) < 0)
    {
        perror("read failure: ");
        return EXIT_FAILURE;
    }

    return atoi(buffer);
}

int main(int argc, char *argv[])
{
    int msgid;
    struct msgbuf msgbuf = {0};

    if ((msgid = fetch()) < 0)
    {
        fprintf(stderr, "fetch failure\n");
        return EXIT_FAILURE;
    }

    if (msgrcv(msgid, &msgbuf, 20, 0, 0) < 0)
    {
        perror("msgrcv failure: ");
        return EXIT_FAILURE;
    }

    printf("%s\n", msgbuf.mtext);

    return EXIT_SUCCESS;
}
