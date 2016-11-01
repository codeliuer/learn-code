#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#include <sqlite3.h>


static const char* psqliteSql = "insert into (%d, %d);";


static void *
memory(const char* format, ...)
{
    void* ptr = NULL;
    va_list list;

    va_start(list, format);
    ptr = sqlite3_vmprintf(format, list);
    va_end(list);

    return ptr;
}

static int
print(const char* format, ...)
{
	int retcode = 0;
	va_list list;

	va_start(list, format);
	retcode = vprintf(format, list);
	va_end(list);

	return retcode;
}


int
main(int argc, char* argv[])
{
    printf("%s\n", memory(psqliteSql, 1, 2));
	print(psqliteSql, 1, 2);
	print("\n");

    return EXIT_SUCCESS;
}
