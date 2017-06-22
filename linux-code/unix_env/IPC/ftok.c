#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    key_t key;
    int msgid;

    msgid = msgget(IPC_PRIVATE, IPC_CREAT|0666);
    printf("msgid = %d\n", msgid);

    msgctl(msgid, IPC_RMID, NULL);

    msgid = msgget(IPC_PRIVATE, IPC_CREAT|0666);
    printf("msgid = %d\n", msgid);

    msgctl(msgid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}
