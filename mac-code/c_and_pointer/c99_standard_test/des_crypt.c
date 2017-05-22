#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <rpc/des_crypt.h>


void des_encrypt(const char *key, char *data, int len)
{
    char pkey[8] = {0};
    strncpy(pkey, key, 8);

    des_setparity(pkey);

    do {
        data[len++] = '\x8';
    } while (len % 8 != 0)

    ecb_crypt(pkey, data, len, DES_ENCRYPT);
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
