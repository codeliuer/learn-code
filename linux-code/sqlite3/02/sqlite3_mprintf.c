#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int
main(int argc, char* argv[])
{
	char* ptr = "It's () [] /%&_a happy day!";
	char buffer[BUFSIZ] = "";

	sprintf(buffer, "\'%s\'", ptr);

	printf("%s\n", sqlite3_mprintf("INSERT INTO table VALUES (\"%q\", \"%q\")", buffer, "333"));

	printf("%s\n", sqlite3_mprintf("REPLACE INTO EPG (_index, eventId, startTime, endTime, duration, name, description, extension, nibbles, serviceIndex) VALUES (0, %d, datetime(\"%s\"), datetime(\"%s\",\'+%d seconds\'), %d, \"%q\", \"%q\", \"%q\", \'%02x%02x%02x%02x\', %d);", 1, "2016-04-04", "2016-04-04", 100, 100, "liuwei", "aaaa'sad", "asdf\"asdf", 0x1, 0x2, 0x3, 0x4, 2));

	return EXIT_SUCCESS;
}
