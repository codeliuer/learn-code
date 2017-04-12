#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern void func(void);


int main(int argc, char *argv[])
{
    func();

    return EXIT_SUCCESS;
}
