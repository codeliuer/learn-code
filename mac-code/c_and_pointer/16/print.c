#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


static void
print_m(const char* format, ...)
{
    va_list va;

    va_start(va, format);
    vprintf(format, va);
}

int
main(int argc, char* argv[])
{
    print_m("%d, %d\n", 3, 4);
    print_m("%d, %s\n", 3, "111122223333");

    return EXIT_SUCCESS;
}
