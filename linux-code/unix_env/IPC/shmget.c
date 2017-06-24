#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define ARRAY_SIZE          (1000)


static int array[ARRAY_SIZE];


int main(int argc, char *argv[])
{
    int shmid = 0;
    void *p = NULL;
    void *shmptr = NULL;

    printf("global array address from %p to %p\n", &array[0], &array[ARRAY_SIZE]);

    p = malloc(ARRAY_SIZE);
    assert(p);

    printf("heap address %p\n", p);

    shmid = shmget(IPC_PRIVATE, 100, IPC_CREAT|0644);
    if (shmid < 0)
    {
        perror("shmget failure: ");
        return EXIT_FAILURE;
    }

    shmptr = shmat(shmid, NULL, 0);    
    if (shmptr == NULL)
    {
        perror("shmat failure: ");
        return EXIT_FAILURE;
    }

    printf("shm address: %p\n", shmptr);

    shmdt(shmptr);

    shmctl(shmid, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}
