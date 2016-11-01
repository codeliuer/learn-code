#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


//#define CREATE_SUCCESS     (1)


#define DB_NAME	           "db_name.db"


static const char *pcreatetable = 
"CREATE TABLE test"
"("
"ID       INT      NOT NULL  PRIMARY KEY,"
"NAME    TEST     NOT NULL,"
"AGE     INT	   NOT NULL,"
"ADDRESS CHAR(50),"
"SALARY  REAL"
");";

static const char *pgetdll = "SELECT sql FROM sqlite_master WHERE tbl_name=\"test\"";


static int 
func(void *arg, int num, char **values, char **names)
{
	static int count = 0;

	count++;
	printf("num = %d, count = %d\n", num, count);
	printf("line = %d, %s\n", __LINE__, values[0]);

	return 0;
}


int
main(int argc, char* argv[])
{
	int retcode = 0;
	char asql[BUFSIZ] = "";
	sqlite3 *phandle = NULL;
	char *perrmsg = NULL;

	retcode = sqlite3_open(DB_NAME, &phandle);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "open db failure\n");
		return EXIT_FAILURE;
	}

#ifdef CREATE_SUCCESS
	retcode = sqlite3_exec(phandle, pcreatetable, NULL, NULL, &perrmsg);
	printf("asdfasdfasdfadsfasdfasdfas\n");
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", perrmsg);
		sqlite3_free(perrmsg);
		return EXIT_FAILURE;
	}
#endif //CREATE_SUCCESS

	retcode = sqlite3_exec(phandle, pgetdll, func, asql, &perrmsg);
	if (retcode != SQLITE_OK)
	{
		fprintf(stderr, "%s\n", perrmsg);
		sqlite3_free(perrmsg);
		return EXIT_FAILURE;
	}

	if (strcmp(asql, pcreatetable) == 0)
	{
		printf("equal\n");
	}

	sqlite3_close(phandle);

	return EXIT_SUCCESS;
}
