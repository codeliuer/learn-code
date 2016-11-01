#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
print(const char* const* ppbuffer, size_t num)
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		printf("%s\n", ppbuffer[i]);
	}
}


int
main(int argc, char* argv[])
{
	const char* buffer[] = 
		{
			"liuwei",	"liuhui",	"liunao",
		};

	print(buffer, sizeof(buffer)/sizeof(buffer[0]));

	return EXIT_SUCCESS;
}
