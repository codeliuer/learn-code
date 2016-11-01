#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


const char* pSqlBuffer = "SELECT frequency FROM epg WHERE duration=%d;";


static int 
callback(void* arg, int num, char** column_values, char** column_name)
{
	static int i = 0;

	if (num == 0)
	{
		printf("num = %d\n", num);
		return 0;
	}

	i++;
	printf("i = %d\n", i);

	*(int *)arg = atoi(column_values[0]);
	printf("indexProgram start = %d\n", *(int *)arg);

	return 0;
}


int
main(int argc, char* argv[])
{
	int retcode = 0;
	int indexProgram = 0;
	sqlite3* phandle = NULL;
	char buffer[BUFSIZ] = "";

	retcode = sqlite3_open("memory.db", &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "open database failure\n");
		return EXIT_FAILURE;
	}

	snprintf(buffer, sizeof(buffer), pSqlBuffer, 0);
	retcode = sqlite3_exec(phandle, buffer, callback, &indexProgram, NULL);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "failure\n");
		return EXIT_FAILURE;
	}

	printf("indexProgram end = %d\n", indexProgram);

	return EXIT_SUCCESS;
}
