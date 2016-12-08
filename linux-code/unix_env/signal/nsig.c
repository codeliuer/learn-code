#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("NSIG = %d\n", NSIG);

    return EXIT_SUCCESS;
}
