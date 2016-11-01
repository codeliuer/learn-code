#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define DBFILENAME          "program.db"


int
main(int argc, char* argv[])
{
    int ret = 0;
    sqlite3* handle = NULL;

    ret = sqlite3_open(DBFILENAME, &handle);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "open %s failure\n", DBFILENAME);
        return EXIT_FAILURE;
    }

    if (database_insert(""))

    ret = sqlite3_close(handle);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "close %s failure\n", DBFILENAME);
    }

    return EXIT_SUCCESS;
}
