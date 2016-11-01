#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ARRAY
{
    int         nums;
    int         test_arr[];
};


static struct ARRAY array = 
        {3, {1, 2, 3}};


int
main(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}
