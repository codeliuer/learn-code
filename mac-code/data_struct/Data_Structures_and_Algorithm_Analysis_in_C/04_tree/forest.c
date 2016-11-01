/*
** forest operator interface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct FOREST
{
    void            *pdata;
    struct FOREST   arr[];
} FOREST;


typedef int (*CMP_t)(const void *, const void *);


static FOREST *
make_node(size_t len)
{
    FOREST *tmp = calloc(len, 1);
    assert(tmp != NULL);

    return tmp;
}


int 
insert_forest(FOREST **root, void *pdata, CMP_t cmp)
{
    return 0;
}


int 
show_forest(FOREST *root)
{
    int i = 0;

    if (root != NULL)
    {
        printf("%s  ", (const char *)root->pdata);

        for (i = 0; root->arr[i] != NULL; i++)
        {
            show_forest(root->arr[i]);
        }
    }

    return 0;
}


static int 
total(const char *str)
{
    int total = 0;

    while (*str != 0)
    {
        total += *str++;
    }

    return total/10;
}


static int 
calcul(const char *str1, const char *str2)
{
    return total(str1) == total(str2);
}


int 
cmp(const void *data1, const void *data2)
{
    const char *str1 = *(const char **)&data1;
    const char *str2 = *(const char **)&data2;
    
    return calcul(data1, data2);
}


int
main(int argc, char * argv[])
{
    FOREST *first = NULL;

    insert_forest(&first, "liuwei", cmp);
    insert_forest(&first, "liuwei", cmp);
    show_forest(first);

    return EXIT_SUCCESS;
}
