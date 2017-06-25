#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/mman.h>

#include "process_sync/sync.h"


int main(int argc, char *argv[])
{
    int fd;

    fd = open("/dev/zero", "w+");

    return EXIT_SUCCESS;
}
