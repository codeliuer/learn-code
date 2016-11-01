#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define	AUTOLEN					(-1)
#define	DB_FILENAME				"program_bak.db"


#define	SQL_STATEMENT(table)									\
	const char* psqlReadBlob =									\
	{															\
		"UPDATE " #table " SET pmtsection=\"123456\"			\
		WHERE tsId=11 AND frequency=387000 AND serviceId=127"	\
	};

SQL_STATEMENT(program);

//static char* sql = "SELECT pmtsection FROM program WHERE tsId=11 AND serviceId=127";
static char* sql = "SELECT pmtsection FROM program";

static int
callback(void* arg, int num, char** column_values, char** column_name)
{
	printf("name: %s, value = %s\n", column_name[0], column_values[0]);

	return 0;
}

static void
show(const void* ptr, int num)
{
	printf("0X");
	while (num--)
	{
		printf("%02x ", *(unsigned char *)ptr++);
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	int i = 0;
	int ret = 0;
	int nbytes = 0;
	char* errmsg = NULL;
	struct sqlite3_stmt* stmt = NULL;
	sqlite3* phandle = NULL;

	ret = sqlite3_open(DB_FILENAME, &phandle);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "open %s failure, return code = %d\n", DB_FILENAME, ret);
		return ret;
	}

	ret = sqlite3_prepare_v2(phandle, sql, AUTOLEN, &stmt, NULL);
	if (ret != SQLITE_OK)
	{
		fprintf(stderr, "return code = %d\n", ret);
	}

	while (1)
	{
	ret = sqlite3_step(stmt);
	if (ret != SQLITE_ROW)
	{
		fprintf(stderr, "get data failure return code = %d\n", ret);
		return ret;
	}

	const void* ptr = sqlite3_column_blob(stmt, i);
	nbytes = sqlite3_column_bytes(stmt, i);
	printf("nbytes = %d\n", nbytes);

	sqlite3_reset(stmt);

	show(ptr, nbytes);
	i++;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(phandle);

	return EXIT_SUCCESS;
}
