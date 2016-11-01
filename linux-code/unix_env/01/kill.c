#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


int
main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./a.out signal numner\n");
        return EXIT_FAILURE;
    }

    kill(atoi(argv[1]), SIGSEGV);

    return EXIT_SUCCESS;
}
