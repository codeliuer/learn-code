#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	char* str = "It' \"s ";
	char* ptr = sqlite3_mprintf("INSERT INTO EPG VALUES('%w')", str);
	printf("%s\n", ptr);
	sqlite3_free(ptr);

	return EXIT_SUCCESS;
}
