#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define	SQL_NEW_TABLE(table, field, value)			"REPLACE INTO " #table " VALUES(\"" field "\",\'" #value "\')"
#define SQL_SYSTEM_TABLE(field, value)				SQL_NEW_TABLE(systemParameter, field, value)


int
main(int argc, char* argv[])
{
	int ret = 0;
	char* error = NULL;
	sqlite3* handle = NULL;

	ret = sqlite3_open("system.db", &handle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "handle get failure\n");
		return EXIT_FAILURE;
	}

	ret = sqlite3_exec(handle, SQL_SYSTEM_TABLE("aaaaa", 1), NULL, NULL, &error);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "%s  error\n", error);
		return EXIT_FAILURE;
	}

	sqlite3_close(handle);

	return EXIT_SUCCESS;
}
