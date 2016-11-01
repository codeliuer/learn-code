#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	int retcode = 0;
	sqlite3* phandle = NULL;

	retcode = sqlite3_open_v2("db", &phandle, SQLITE_OPEN_READWRITE, NULL);
	if (retcode != SQLITE_OK)
	{
		printf("%s\n", sqlite3_errmsg(phandle));
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
