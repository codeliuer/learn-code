#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define DBFILENAME          "program.db"

#define OK                  (0)
#define NO                  (1)

#ifndef DEBUG
# define ENTER_DATABASE      printf("enter %s\n", __FUNCTION__)
# define QUIT_DATABASE       printf("exit %s\n", __FUNCTION__)
#else
# define ENTER_DATABASE
# define QUIT_DATABASE
#endif

static int 
callback(void* arg, int num, char** values, char** name)
{
    int i = 0;

    printf("number = %d\n", num);
    for (i = 0; i < num; i++)
    {
        printf("%s: %s\n", name[i], values[i]);
    }

    return 0;
}

static void
print_table(char** dbResult, int nRow, int nColumn)
{
    int i = 0;
    int j = 0;
    int index = nColumn;

    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nColumn; j++)
        {
            printf("%s  %s\n", dbResult[j], dbResult[index]);
            index++;
        }

        printf("#######################################\n");
    }
}

static int 
database_query(sqlite3* handle)
{
    int ret = 0;
    int nRow = 0;
    int nColumn = 0;
    const void* blobData = NULL;
    char** dbResult = NULL;
    sqlite3_stmt* stat = NULL;

//    ret = sqlite3_exec(handle, "SELECT frequency FROM program WHERE serviceid = 22; SELECT pmtPID, name, polarization, modulation, soundChannel, systemid FROM program WHERE serviceid = 23;", callback, 0, 0);

//    ret = sqlite3_get_table(handle, "SELECT * FROM program", &dbResult, &nRow, &nColumn, NULL);
//    print_table(dbResult, nRow, nColumn);
//    sqlite3_free_table(dbResult);
    
    ret = sqlite3_prepare(handle, "SELECT pmtsection FROM program WHERE serviceId=24", -1, &stat, NULL);
    if (ret != SQLITE_ROW && ret != SQLITE_OK)
    {
        fprintf(stderr, "prepare failure ret = %d\n", ret);
        return NO;
    }
    printf("ret = %d, SQLITE_ROW = %d, SQLITE_OK = %d\n", ret, SQLITE_ROW, SQLITE_OK);

    ret = sqlite3_step(stat);
    nRow = sqlite3_column_bytes(stat, 1);
    if (ret != SQLITE_ROW)
    {
        fprintf(stderr, "step failure\n");
        return NO;
    }

    blobData = sqlite3_column_blob(stat, 0);
    nRow = sqlite3_column_bytes(stat, 0);
    printf("nRow = %d\n", nRow);
    while (nRow--)
    {
        printf("0x%0*x ", 2, *(unsigned char *)blobData);
        blobData++;
    }
    printf("\n");

    ret = sqlite3_finalize(stat);

    return ret;
}

int
main(int argc, char* argv[])
{
    int ret = 0;
    sqlite3* handle = NULL;

    ENTER_DATABASE;

    ret = sqlite3_open(DBFILENAME, &handle);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "database file %s open failure\n", DBFILENAME);
        return EXIT_FAILURE;
    }

    if (database_query(handle) != OK)
    {
        fprintf(stderr, "database query failure\n");
        return EXIT_FAILURE;
    }

    ret = sqlite3_close(handle);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "database file %s close failure\n", DBFILENAME);
        return EXIT_FAILURE;
    }

    QUIT_DATABASE;

    return EXIT_SUCCESS;
}
