#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
print_ledger_default(int value)
{
}


int
main(int argc, char* argv[])
{
#if OPTION_LONG
	print_ledger_long(1);
#elif OPTION_DETAILED
	print_ledger_detailed(2);
#else
	print_ledger_default(3);
#endif	//OPTION_LONG

	return EXIT_SUCCESS;
}
