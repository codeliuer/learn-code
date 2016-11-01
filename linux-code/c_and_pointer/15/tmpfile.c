#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	int num = 100;
	FILE* pfile = tmpfile();

	fwrite(&num, sizeof(num), 1, pfile);
	//fflush(pfile);

	num = 0;
	fseek(pfile, 0, SEEK_SET);
	fread(&num, sizeof(num), 1, pfile);
	printf("num = %d\n", num);

	fclose(pfile);

	printf("TMP_MAX = %d\n", TMP_MAX);
	printf("L_tmpnam = %d\n", L_tmpnam);

	return EXIT_SUCCESS;
}
