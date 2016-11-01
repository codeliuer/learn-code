#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	char buffer[BUFSIZ] = "";
	fpos_t pos = 0;

	FILE* pfile = fopen("fgetpos.c", "r");
	if (pfile == NULL)
	{
		printf("open failure\n");
		return EXIT_FAILURE;
	}

	fgetpos(pfile, &pos);
	printf("pos = %d\n", pos);

	fgets(buffer, sizeof(buffer), pfile);
	printf("%d %s\n", strlen(buffer), buffer);
	fgetpos(pfile, &pos);
	printf("%ld\n", pos);

	return EXIT_SUCCESS;
}
