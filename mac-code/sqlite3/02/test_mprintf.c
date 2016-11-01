#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


static int callback(void* arg, int num, char** column_value, char** column_name)
{
	strcpy((char *)arg, column_value[0]);
}

int
main(int argc, char* argv[])
{
	int retcode = 0;
	int i=0;
	sqlite3* phandle = NULL;
	char* errmsg = NULL;
	char buffer[10000] = "";
	char* ptr = NULL;

	retcode = sqlite3_open("db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "line: %d, retcode = %d\n", __LINE__, retcode);
		return EXIT_FAILURE;
	}

	sqlite3_exec(phandle, "SELECT str1 FROM test WHERE int1=1", callback, buffer, NULL);
	printf("%s\n", buffer);

	return EXIT_SUCCESS;
}
