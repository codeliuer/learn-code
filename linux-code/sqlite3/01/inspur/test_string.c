#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	int retcode = 0;
	sqlite3* phandle = NULL;

	retcode = sqlite3_open("system.db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "get system.db failure, return code = %d\n", retcode);
		return EXIT_FAILURE;
	}

	retcode = sqlite3_exec(phandle, "REPLACE INTO systemParameter VALUES('programDataVersion', '0')", 0, 0, 0);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "return code = %d\n", retcode);
		return EXIT_FAILURE;
	}

	sqlite3_close(phandle);

	return EXIT_SUCCESS;
}





















