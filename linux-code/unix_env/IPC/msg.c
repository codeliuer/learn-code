#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>


extern int errno;

int main(int argc, char *argv[])
{
    key_t key = 0;
    int msgid = 0;
    struct msqid_ds msg_ds;
    
    key = ftok("file", 1);
    if (key < 0)
    {
        perror("ftok failure: ");
        return EXIT_FAILURE;
    }

    msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
    if (msgid < 0)
    {
        if (errno == EEXIST)
        {
            msgid = msgget(key, 0644);
            if (msgid < 0)
            {
                perror("msgget failure: ");
                return EXIT_FAILURE;
            }
        }
        else
        {
            perror("msgget failure: ");
            return EXIT_FAILURE;
        }
    }

    if (msgctl(msgid, IPC_STAT, &msg_ds) < 0)
    {
        perror("msgctl failure: ");
        return EXIT_FAILURE;
    }

    printf("msg_qnum = %ld\n", msg_ds.msg_qnum);
    printf("msg_qbytes = %ld\n", msg_ds.msg_qbytes);
    printf("key = %d\n", msg_ds.msg_perm.__key);
    printf("mode = %#o\n", msg_ds.msg_perm.mode);
    printf("__seq = %d\n", msg_ds.msg_perm.__seq);

    return EXIT_SUCCESS;
}
