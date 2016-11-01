/*
** test chinese compare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	char* ptr = "中国的";
	
	if (strcmp(ptr, "中国的") == 0)
	{
		printf("chinese is able compare\n");
	}
	else
	{
		printf("chinese isn't able compare\n");
	}

	return EXIT_SUCCESS;
}
