#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	paste(CK_, name)			CK_##name

#define	TEST(a)				({int b = (a)*(a); b = b*b; b;})


const char* ptr = "1111111111111111111111"   "2222222222222222222222"
"333333333333333333333333333333333" "4444444444444444444444444444444"
"5555555555555555555555555555555555";


static int
paste(CK_, name)(void)
{
	printf("name\n");
}


int
main(int argc, char* argv[])
{
	printf("%s\n", ptr);

	printf("%s\n", "aaaaa" "bbbbb");
	printf("%s\n", "aaaaa""bbbbb");

	printf("CK_name = %d\n", CK_name());
	printf("TEST(2) = %d\n", TEST(2));

	return EXIT_SUCCESS;
}
