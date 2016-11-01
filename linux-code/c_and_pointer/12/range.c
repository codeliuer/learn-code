#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	sql_name_haha			"name 1"
#define	array_num(arr)			(sizeof(arr)/sizeof(arr[0]))

#define	SQL_Exec(name)						\
	static void sql_##name##_exec(void)				\
{											\
	int i = 0;								\
	char* haha[] =							\
		{									\
			sql_##name##_haha,				\
			sql_##name##_haha,				\
			sql_##name##_haha,				\
		};									\
											\
	for (i = 0; i < array_num(haha); i++)	\
	{										\
		printf("%s\n", haha[i]);			\
	}										\
}

SQL_Exec(name);

int
main(int argc, char* argv[])
{
	sql_name_exec();

	return EXIT_SUCCESS;
}
