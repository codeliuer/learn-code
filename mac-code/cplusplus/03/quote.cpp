#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>


#define print_addr(format, ...)		printf(format, ##__VA_ARGS__)
#define print_base(format, ...)		printf(format, ##__VA_ARGS__)
#define print_proc(process)			printf("%s", #process);
#define print_func()				printf("%s: ", __func__)

#define newline						std::cout << std::endl

#define defvar(a)					a; printf("%s: %-30s", __func__, #a)
#define defvar2(a)					defvar(a)
#define callfunc(a)					printf("%s: %-30s", __func__, #a); newline; a

#define align						""

#ifdef __x86_64__
# define		align_type			unsigned long
# define		align_char			8 
#elif __i386__
# define		align_type			unsigned int
# define		align_char			4
#else
# error "not support\n"
#endif 

#define MACHINE_32BIT				4
#define MACHINE_64BIT				8

#define replace_action(ptr)																					\
	do	{																									\
			defvar2(align_type *palias = (align_type *)(((char *)ptr) - align_char));		newline;		\
																											\
			print_func(); print_base("*palias = %#lx", *palias);		newline;							\
	} while (0)

#define machine_action()									\
	do {													\
		if (align_char == MACHINE_64BIT)					\
		{													\
			defvar(int *nmax = pmax-1);		newline;		\
															\
			replace_action(nmax);							\
		}													\
		else												\
		{													\
			replace_action(pmax);							\
		}													\
	} while (0)


using namespace std;

static void test(int first, int& quote_first, int second)
{
	newline;

	print_func(); print_base("static void test(int first, int& quote_first, int second)");	newline;

	newline;

	print_func(); print_addr("%sfirst address       = %p", align, &first);			newline;
	print_func(); print_addr("%squote_first address = %p", align, &quote_first);		newline;
	print_func(); print_addr("%ssecond address      = %p", align, &second);			newline;

	newline;

	if (&second > &first)
	{
		defvar(int *pmax = &second);		newline;

		machine_action();
	}
	else
	{
		defvar(int *pmax = &first);			newline;
		
		machine_action();
	}

}

int main(int argc, char *argv[])
{
	print_base("sizeof(int) = %lu, sizeof(void *) = %lu\n", sizeof(int), sizeof(void *));

	newline;
	defvar(int v1 = 100);		print_addr("v1 address = %p", &v1);		 newline;
	defvar(int v2 = 200);		print_addr("v2 address = %p", &v2);		 newline;
	defvar(int v3 = 300);		print_addr("v3 address = %p", &v3);		 newline;

	newline;

	defvar(int        first = 100);			print_addr("first address       = %p", &first);			 newline;
	defvar(int &quote_first = first);		print_addr("quote_first address = %p", &quote_first);	 newline;
	defvar(int       second = 200);			print_addr("second address      = %p", &second);		 newline;

	newline;

	callfunc(test(first, quote_first, second));	

	return EXIT_SUCCESS;
}
