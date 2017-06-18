#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main(int argc, char *argv[])
{
    key_t key = 0;
    
    key = ftok("/home/parallels", 1);

    return EXIT_SUCCESS;
}
