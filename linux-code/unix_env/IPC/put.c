#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    setbuf();

    fprintf(stdout, "hello\n");

    _exit(EXIT_FAILURE);
}
