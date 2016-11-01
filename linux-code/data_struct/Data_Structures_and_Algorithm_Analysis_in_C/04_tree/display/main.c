/*
** display directory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dir.h"


int
main(int argc, char * argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out directory\n");
        return EXIT_FAILURE;
    }

    show_dir(argv[1]);

    return EXIT_SUCCESS;
}
