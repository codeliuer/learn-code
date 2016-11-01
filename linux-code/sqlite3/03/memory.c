#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	int ret = 0;
	char* error = NULL;
	sqlite3* handle = NULL;

	ret = sqlite3_open("memory.db", &handle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "handle get failure\n");
		return EXIT_FAILURE;
	}

	ret = sqlite3_exec(handle, "REPLACE INTO timeshift_event VALUES(\"programDataVer\", '0')", NULL, NULL, &error);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "%s  error\n", error);
		return EXIT_FAILURE;
	}

	sqlite3_close(handle);

	return EXIT_SUCCESS;
}
