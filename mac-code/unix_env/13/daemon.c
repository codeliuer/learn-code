#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    daemon(0, 0);

    printf("asdfadsfasdfas\n");

    return EXIT_SUCCESS;
}
