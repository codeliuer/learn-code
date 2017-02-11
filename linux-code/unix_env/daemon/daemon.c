#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <syslog.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
    const char *cmd =  "daemon test";

    daemon(0, 0);

    opensys(cmd, );

    return EXIT_SUCCESS;
}
