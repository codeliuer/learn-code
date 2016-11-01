#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>


#define	DATA_PRINT(format, ...)		fprintf(stderr, format, ##__VA_ARGS__);


int
main(int argc, char* argv[])
{
	DATA_PRINT("%s %s %d error\n", "luxiaofeng", "wocaonimeide", 20);

	return EXIT_SUCCESS;
}


























