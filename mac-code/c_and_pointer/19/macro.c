#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void func(void);

int
main(int argc, char* argv[])
{
	func();

	return EXIT_SUCCESS;
}

static void
func(void)
{
	printf("function = %d\n", __LINE__);
}

#define	func		aa
static void
func(void)
{
	printf("function = %d\n", __LINE__);
}
