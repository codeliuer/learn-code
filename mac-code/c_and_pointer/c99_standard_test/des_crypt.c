#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <rpc/des_crypt.h>


void des_encrypt(const char *key, char *data, int len)
{
    char pkey[10] = {0};
    strncpy(pkey, key, 8);

    des_setparity(pkey);

    do {
        data[len++] = '\x8';
    } while (len % 8 != 0);

    ecb_crypt(pkey, data, len, DES_ENCRYPT);
}

static void show(const char *data, int len)
{
    int i = 0;

    for (i = 0; i < len; i++)
    {
        printf("%x", *(unsigned char *)&data[i]);
    }
}

int main(int argc, char *argv[])
{
    const char key[] = "12345678";
    char *data = NULL;

    des_encrypt(key, data, 8);
    
    return EXIT_SUCCESS;
}
