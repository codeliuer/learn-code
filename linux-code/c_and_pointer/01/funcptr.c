#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


typedef void (*funcptr)(void);

static void
name(void)
{
	printf("my name is liuwei\n");
}

static void
myname(void)
{
	printf("my name is liuwei\n");
}

int
main(int argc, char* argv[])
{
	funcptr func[] = {name, myname};

	func[0]();
	func[1]();

	return EXIT_SUCCESS;
}
