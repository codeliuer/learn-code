#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>


#define print_addr(format, ...)		printf(format, ##__VA_ARGS__)
#define print_base(format, ...)		printf(format, ##__VA_ARGS__)
#define print_proc(process)			printf("%s", #process)

#define newline						std::cout << std::endl

#define defvar(a)					a; printf("%s: %-30s", __func__, #a)
#define callfunc(a)					printf("%s: %-30s", __func__, #a); newline; a

#define align						"        "

using namespace std;

static void test(int first, int& quote_first, int second)
{
	print_addr("%sfirst address       = %p", align, &first);			newline;
	print_addr("%squote_first address = %p", align, &quote_first);		newline;
	print_addr("%ssecond address      = %p", align, &second);			newline;

	newline;

	defvar(int *psecond  = &second);		newline;
	defvar(int *npsecond = &second-1);		newline;
}

int main(int argc, char *argv[])
{
	print_base("sizeof(int) = %lu, sizeof(void *) = %lu\n", sizeof(int), sizeof(void *));

	newline;

	defvar(int        first = 100);			print_addr("first address       = %p", &first);			 newline;
	defvar(int &quote_first = first);		print_addr("quote_first address = %p", &quote_first);	 newline;
	defvar(int       second = 200);			print_addr("second address      = %p", &second);		 newline;

	newline;

	callfunc(test(first, quote_first, second));	

	return EXIT_SUCCESS;
}
