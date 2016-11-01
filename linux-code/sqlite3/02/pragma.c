#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


static const char* sql_create_test_table = 
"CREATE TABLE IF NOT EXISTS test(i1 INTEGER, i2 INTEGER, i3 VARCHAR(60), i4 VARCHAR(10), PRIMARY KEY(i1, i2, i4));";

static const char* sql_pragma_schema_table_info = ".tables";
//"PRAGMA schema.table_info(test);";


static int 
callback(void* arg, int num, char** values, char** name)
{
    printf("%s\n", values[0]);
    return 0;
}

int
main(int argc, char* argv[])
{
    char* errmsg = NULL;
    sqlite3* phandle = NULL;

    sqlite3_open("test", &phandle);

    sqlite3_exec(phandle, sql_create_test_table, NULL, NULL, &errmsg);
    printf("%s\n", errmsg == NULL ? "NULL" : errmsg);
    sqlite3_free(errmsg);
        
    sqlite3_exec(phandle, sql_pragma_schema_table_info, callback, NULL, &errmsg);
    printf("%s\n", errmsg == NULL ? "NULL" : errmsg);
    sqlite3_free(errmsg);

    return EXIT_SUCCESS;
}
