#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int main(int argc, char *argv[])
{
    key_t key;
    int semid = 0;

    key = ftok("/home/parallels", 2);
    if (key < 0)
    {
        perror("ftok failure: ");
        return EXIT_FAILURE;
    }

    semid = semget(key, 129, IPC_CREAT|0666);
    if (semid < 0)
    {
        perror("semget failure: ");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
