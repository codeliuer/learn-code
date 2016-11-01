#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE
{
    int     value;
    char    name[20];
    double  d;
};


static struct NODE null_node = {0};
#define NULL_NODE           ((struct NODE)null_node)


static int 
isnull(struct NODE* node)
{
    size_t len = sizeof(*node);

    while (len--)
    {
        if (((char *)node)[len] != 0)
        {
            return -1;
        }
    }

    return 0;
}


int
main(int argc, char* argv[])
{
    struct NODE node = {0};

    /* struct type not compare */
    if (isnull(&node) == 0)
    {
        printf("null node\n");
    }
    else
    {
        printf("compare failure\n");
    }

    return EXIT_SUCCESS;
}
