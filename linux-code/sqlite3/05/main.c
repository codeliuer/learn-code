#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#include "query.h"


#define	MEMORYDB			"memory.db"
#define	EPGDB				"dvb_provider_epg1.db"


int
main(int argc, char* argv[])
{
	struct HEAD_t* head = NULL;

	printf(MEMORYDB " repeat:\n");
	head = query(head, MEMORYDB, MEMORYF);
	printf("******************************************************************\n");

	printf(EPGDB " repeat:\n");
	head = query(head, EPGDB, APKEPGF);
	printf("*******************************************************************\n");

	printf("###########################not find################################:\n");
	compare(head);

	return EXIT_SUCCESS;
}
