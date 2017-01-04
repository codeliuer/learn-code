#include <stdio.h>
#include <stdlib.h>

#include "self_io.h"


int main(int argc, char *argv[])
{
    printinfo("3\n");

    fprintinfo(stderr, "3\n");

    return EXIT_SUCCESS;
}
