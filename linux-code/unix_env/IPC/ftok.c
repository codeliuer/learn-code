#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


#define MIDFILE         "midfile"

static int saveid(int id)
{
    int fd = 0;

    fd = open(MIDFILE, O_CREAT|O_RDWR, 0666);
    if (fd < 0)
    {
        perror("open failure: ");
        return EXIT_FAILURE;
    }

    write();

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int msgid;

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

    return EXIT_SUCCESS;
}
