#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define	DB_NAME			"program.db"


static int callback(void* arg, int num, char** col, char** row)
{
	return 0;
}

int
main(int argc, char* argv[])
{
	int ret = 0;
	char* errmsg = NULL;
	sqlite3* phandle = NULL;

	ret = sqlite3_open(DB_NAME, &phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "sqlite3_open %s failure, error code = %d\n", DB_NAME, ret);
		return ret;
	}

	ret = sqlite3_exec(phandle, "CREATE TABLE persons (filed1, filed2, filed3)", callback, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "sqlite_exec perform failure, error code = %d, error msg: %s\n", ret, errmsg);
		sqlite3_free(errmsg);
		return ret;
	}

	ret = sqlite3_close(phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "sqlite_close perform failure, error code = %d\n", ret);
		return ret;
	}

	return EXIT_SUCCESS;
}
