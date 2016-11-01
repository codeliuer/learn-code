#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int
main(int argc, char* argv[])
{
    char u[] = {0x65, 0x66, 0x67, 0x68, 0x69,};
    time_t tm = time(NULL);

    struct tm* pt = localtime(&tm);

    printf("pt->pt_year = %d\n", pt->tm_year);
    printf("pt->pt->");

    printf("sizeof(u) = %lu\n", sizeof(u));

    return EXIT_SUCCESS;
}
