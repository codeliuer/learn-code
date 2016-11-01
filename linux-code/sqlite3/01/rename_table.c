#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


#define	DB_NAME				"test"

#define	PERSON_COLUMN		"(firstName, lastName, arg, high, weight)"
#define	PERSON_FORMAT		"(\"%s\", \"%s\", %d, %d, %d)"

#define	CREATE_PERSONS(table_name)							\
	static const char* psql_create_##table_name =			\
		{													\
			"CREATE TABLE " #table_name PERSON_COLUMN		\
		}

CREATE_PERSONS(persons);
CREATE_PERSONS(persons2);

#define	INSERT_PERSONS(table_name)												\
	static const char* psql_insert_##table_name =								\
		{																		\
			"INSERT INTO " #table_name PERSON_COLUMN " VALUES " PERSON_FORMAT	\
		}

INSERT_PERSONS(persons);
INSERT_PERSONS(persons2);

#define	DELETE_TABLE(table_name)							\
	static const char* psql_delete_##table_name =			\
		{													\
			"DROP TABLE " #table_name						\
		}

DELETE_TABLE(person);

#define	SQL_RETCODE_CHECK(code)										\
	do{																\
		if (code != SQLITE_OK)										\
		{															\
			fprintf(stderr, "line = %d "							\
					"sqlite return code = %d\n", __LINE__, ret);	\
			return code;											\
		}															\
	} while (0)

int
main(int argc, char* argv[])
{
	int ret = 0;
	sqlite3* phandle = NULL;
	char sqlbuffer[BUFSIZ] = {0}; 

	ret = sqlite3_open(DB_NAME, &phandle);
	SQL_RETCODE_CHECK(ret);

	ret = sqlite3_exec(phandle, psql_create_persons, 0, 0, 0);
	SQL_RETCODE_CHECK(ret);

	ret = sqlite3_exec(phandle, psql_create_persons2, 0, 0, 0);
	SQL_RETCODE_CHECK(ret);

 	sprintf(sqlbuffer, "INSERT INTO persons2 (firstName, lastName, arg, high, weight) VALUES (\"liu\", \"wei\", 10, 10, 10)");
	ret = sqlite3_exec(phandle, sqlbuffer, 0, 0, 0);
	SQL_RETCODE_CHECK(ret);


// 	sprintf(sqlbuffer, "INSERT INTO persons2 (firstName, lastName, arg, high, weight) VALUES (\"%s\", \"%s\", %d, %d, %d)", "liu", "wei", 10, 10, 10);
//	ret = sqlite3_exec(phandle, sqlbuffer, 0, 0, 0);
//	SQL_RETCODE_CHECK(ret);

	
 	sprintf(sqlbuffer, psql_insert_persons2, "liu", "wei", 10, 10, 10);
	ret = sqlite3_exec(phandle, sqlbuffer, NULL, NULL, NULL);
	SQL_RETCODE_CHECK(ret);


	sprintf(sqlbuffer, psql_insert_persons2, "lu", "xiaofeng", 20, 20, 20);
	ret = sqlite3_exec(phandle, sqlbuffer, NULL, NULL, NULL);
	SQL_RETCODE_CHECK(ret);

	sprintf(sqlbuffer, psql_insert_persons2, "huang", "tianjiao", 30, 30, 30);
	ret = sqlite3_exec(phandle, sqlbuffer, NULL, NULL, NULL);
	SQL_RETCODE_CHECK(ret);

	ret = sqlite3_exec(phandle, "DROP TABLE persons", NULL, NULL, NULL);
	SQL_RETCODE_CHECK(ret);

	ret = sqlite3_exec(phandle, "ALTER TABLE persons2 RENAME TO persons", NULL, NULL, NULL);
	SQL_RETCODE_CHECK(ret);

	ret = sqlite3_close(phandle);
	SQL_RETCODE_CHECK(ret);

	return EXIT_SUCCESS;
}
