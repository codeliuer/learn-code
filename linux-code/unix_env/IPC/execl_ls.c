#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    execl("/usr/bin/who", "", (char *)0);

    return EXIT_SUCCESS;
}
