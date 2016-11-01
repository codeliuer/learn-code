#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
	int retcode = 0;
	char* perrmsg = NULL;
	sqlite3* phandle = NULL;

	retcode = sqlite3_open("db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "failure\n");
		return EXIT_FAILURE;
	}

	retcode = sqlite3_exec(phandle, "BEGIN TRANSACTION", NULL, NULL, &perrmsg);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", perrmsg);
		return EXIT_FAILURE;
	}

	retcode = sqlite3_exec(phandle, 
			"INSERT INTO test(name, id) VALUES(\"liu\", \"2\")",
			NULL, NULL, &perrmsg);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", perrmsg);
		return EXIT_FAILURE;
	}

	sleep(10);

	retcode = sqlite3_exec(phandle, "commit transaction", NULL, NULL, &perrmsg);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", perrmsg);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
