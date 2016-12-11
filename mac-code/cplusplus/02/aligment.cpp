#include <stdlib.h>
#include <iostream>


struct 
{
	char c;
	short b;
	long l;
} u;

int main(int argc, char *argv[])
{
	std::cout << sizeof(u) << std::endl;
 
	return EXIT_SUCCESS;
}
