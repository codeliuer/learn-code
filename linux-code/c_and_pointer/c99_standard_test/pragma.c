#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LISTING(x)          PRAGMA(listing on #x)
#define PRAGMA(x)           _Pragma(x)

LISTING(..\listing.dir)


int
main(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}
