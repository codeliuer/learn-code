#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	int retcode = 0;
	char* perrmsg = NULL;
	sqlite3* phandle = NULL;

	//retcode = sqlite3_open("db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", sqlite3_errmsg(phandle));
		return EXIT_FAILURE;
	}
	fprintf(stderr, "%s\n", sqlite3_errmsg(phandle));

	retcode = sqlite3_busy_handler(phandle, NULL, NULL);
	if (retcode == SQLITE_OK)
	{
		fprintf(stderr, "%s\n", sqlite3_errmsg(phandle));
	//	return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
