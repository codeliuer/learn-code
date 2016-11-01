#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	UNUSED(x)		(void)(x)


typedef struct ENUM_t
{
	enum {ONE, TWO, THERR, ALL};
	char str[4];
} ENUM_t;


static int a = 2;
static int* num = &a;


static ENUM_t e = {""};

int
main(int argc, char* argv[])
{
	UNUSED(num);
	UNUSED(e);
#if defined(TEST_COMPILE_CONSTANT)
	int b = 2;
	static int* pb = &b;
#endif	//TEST_COMPILE_CONSTANT

	return EXIT_SUCCESS;
}
