#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	NAME_TO_STR_v2(table_name)	#table_name
#define	NAME_TO_STR(table_name)		NAME_TO_STR_v2(table_name)


#define	EPG_NAME			epg
#define	EPG_STRING			NAME_TO_STR(EPG_NAME)

//#define	TEST(table)			"DELETE FROM " table " WHERE ";"


static void
func(int num)
{
	char str[num];

	printf("size = %lu\n", sizeof(str));
}

int
main(int argc, char* argv[])
{
	int num;
	//char* ptr = "112233";

	//printf("%s\n", NAME_TO_STR(EPG_NAME));
	
	printf("%p\n", "xyz");
	printf("%p\n", "xyz"+1);

	func(num);

	return EXIT_SUCCESS;
}
