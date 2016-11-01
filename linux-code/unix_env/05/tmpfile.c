/*
** test tmpnam and tmpfile
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXLINE             (200)


int
main(int argc, char* argv[])
{
    FILE* fp = NULL;
    char line[MAXLINE] = "";
    char name[L_tmpnam] = "";

    printf("%s\n", tmpnam(NULL));

    tmpnam(name);
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL)
    {
        fprintf(stderr, "tmpfile error\n");
        return EXIT_FAILURE;
    }
    fputs("one line of output\n", fp);
    rewind(fp);

    if (fgets(line, sizeof(line), fp) == NULL)
    {
        fprintf(stderr, "fgets failure\n");
        return EXIT_FAILURE;
    }
    fputs(line, stdout);

    printf("TMP_MAX = %d\n", TMP_MAX);
    printf("L_tmpnam = %d\n", L_tmpnam);

    return EXIT_SUCCESS;
}
