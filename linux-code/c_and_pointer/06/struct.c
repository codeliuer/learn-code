#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct foo
{
    int a;
    char s[0];
};

struct boo
{
    struct foo* pf;
};


struct coo
{
    int     a[0];
};


int
main(int argc, char* argv[])
{
    struct boo f = {NULL};

    if (f.pf->s)
    {
        printf("f.pf->s = %p\n", f.pf->s);
    }

    printf("sizeof(struct foo) = %lu\n", sizeof(struct foo));
    printf("sizeof(struct coo) = %lu\n", sizeof(struct coo));

    return EXIT_SUCCESS;
}
