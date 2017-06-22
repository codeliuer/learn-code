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

    key = ftok("/home/parallels/", 3);

    msgid = msgget(key, IPC_CREAT|0666);
    printf("msgid = %d\n", msgid);

    msgctl();

    return EXIT_SUCCESS;
}
