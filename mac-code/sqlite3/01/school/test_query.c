#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	sqlite3* phandle = NULL;

	int ret = sqlite3_open("db", &phandle);
	printf("line = %d, retcode = %d\n", __LINE__, ret);

	ret = sqlite3_exec(phandle, "create table name (name VARCHAR(10), id INTEGER)", NULL, NULL, NULL);
	printf("line = %d, retcode = %d\n", __LINE__, ret);

	ret = sqlite3_exec(phandle, "select * from name", NULL, NULL, NULL);
	printf("line = %d, retcode = %d\n", __LINE__, ret);

	sqlite3_close(phandle);

	return EXIT_SUCCESS;
}
