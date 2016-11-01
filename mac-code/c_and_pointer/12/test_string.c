#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	EPG_NAME			epg

#define	CONDITION_DEL2(table, condition)	"DELETE FROM " #table " WHERE " condition
#define	CONDITION_DEL1(table, condition)		CONDITION_DEL2(table, condition)

#define	EPG_CONDITION_DEL(condition)	CONDITION_DEL1(EPG_NAME, condition)


int
main(int argc, char* argv[])
{
	printf("%s\n", EPG_CONDITION_DEL("endTime < dateTime()"));

	return EXIT_SUCCESS;
}
