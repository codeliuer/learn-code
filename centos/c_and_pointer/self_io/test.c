#include <stdio.h>
#include <stdlib.h>

#include "self_io.h"


int main(int argc, char *argv[])
{
    printinfo("3");

    fprintinfo(stderr, "3");

    return EXIT_SUCCESS;
}
