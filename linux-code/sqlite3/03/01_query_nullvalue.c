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
	
	retcode = sqlite3_open("./memory.db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "return code = %d\n", retcode);
		return EXIT_FAILURE;
	}

	retcode = sqlite3_exec(phandle, "SELECT tableId FROM epg WHERE indexEPG = -1", NULL, NULL, &perrmsg);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "return code = %d, error message: (%s)\n", retcode, perrmsg);
		return EXIT_FAILURE;
	}

	sqlite3_close(phandle);

	return EXIT_SUCCESS;
}
