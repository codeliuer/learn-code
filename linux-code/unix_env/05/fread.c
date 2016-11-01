/*
** test fread and fwrite to read and write file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define FILENAME            "tmp.test"
#define NAMESIZE            (16)


typedef struct ITEM_t
{
    short       count;
    long        total;
    char        names[NAMESIZE];
} ITEM_t;


int
main(int argc, char* argv[])
{
    FILE* pfile = NULL;
    ITEM_t item = {10, 20, "liuwei"};
    ITEM_t test = {0};

    pfile = fopen(FILENAME, "w+");
    if (pfile == NULL)
    {
        fprintf(stderr, "open %s failure\n", FILENAME);
        return EXIT_FAILURE;
    }
    unlink(FILENAME);

    fwrite(&item, sizeof(item), 1, pfile);
    fsync(fileno(pfile));
    fseek(pfile, 0, SEEK_SET);
    fread(&test, sizeof(test), 1, pfile);

    printf("test.count = %d\n", test.count);
    printf("test.total = %ld\n", test.total);
    printf("test.names = %s\n", test.names);

    fclose(pfile);

    return EXIT_SUCCESS;
}
