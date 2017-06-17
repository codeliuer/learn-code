#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ipc.h>


int main(int argc, char *argv[])
{
    printf("IPC_PRIVATE = %d\n", IPC_PRIVATE);

    return EXIT_SUCCESS;
}
