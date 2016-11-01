#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	int ret = 0;
	char* errmsg = NULL;
	sqlite3* phandle = NULL;

	if ((ret = sqlite3_open("test", &phandle)) != SQLITE_OK)
	{
		fprintf(stderr, "open failure\n");
		exit(EXIT_FAILURE);
	}

	if ((ret = sqlite3_exec(phandle, "INSERT INTO name VALUES(\"1\", \"2\", \"3\")", NULL, NULL, &errmsg)) != SQLITE_OK)
	{
		fprintf(stderr, "ret = %d, errmsg: %s\n", ret, errmsg);
		sqlite3_free(errmsg);

		return ret;
	}

	sqlite3_close(phandle);

	printf("success\n");

	return EXIT_SUCCESS;
}
