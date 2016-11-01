#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


#define myoffsetof(str_name, member)    ((size_t)&((str_name *)0)->member)


typedef struct ALIGN
{
    char            a_ch;
    int             a_i;
    short int       a_si;
    unsigned int    a_ui;
} ALIGN;


int
main(int argc, char* argv[])
{
    printf("offsetof(struct ALIGN, a_si) = %lu\n", offsetof(ALIGN, a_si));
    printf("myoffsetof(struct ALIGN, a_si) = %lu\n", myoffsetof(ALIGN, a_si));

    return EXIT_SUCCESS;
}
