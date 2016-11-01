#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sqlite3.h>


static int 
callback(void* arg, int num, char** values, char** names)
{
    int i = 0;

    ++*(int *)arg;

    for (i = 0; i < num; i++)
    {
        if (strcmp("indexProgram", names[i]) == 0)
        {
            printf("indexprogram = %s\n", values[i]);
        }
    }

    return 0;
}

int
main(int argc, char* argv[])
{
    int num = 0;
    char* errmsg = NULL;
    sqlite3* phandle = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "usage: ./a.out dbname\n");
        return EXIT_FAILURE;
    }

    sqlite3_open(argv[1], &phandle);
    sqlite3_exec(phandle, "select * from epg", callback, &num, &errmsg);
    printf("num = %d\n", num);

    return EXIT_SUCCESS;
}
