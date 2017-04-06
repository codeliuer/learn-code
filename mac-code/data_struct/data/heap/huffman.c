#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAXSIZE         (20)


typedef struct huffmantree
{
    struct huffmantree      *left;
    struct huffmantree      *right;
    int                     weight;
    struct huffmantree      *parent;
} huffmantree;


static huffmantree htree[MAXSIZE];

static void htree_init(void)
{
    int i = 0;

    srand(time(NULL));
    for (i = 0; i < MAXSIZE; i++)
    {
        htree[i].left = NULL;
        htree[i].right = NULL;
        htree[i].weight = rand()%MAXSIZE+1;
        htree[i].parent = NULL;
    }
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
