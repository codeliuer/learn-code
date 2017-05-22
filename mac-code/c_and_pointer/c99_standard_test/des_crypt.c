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


int main(int argc, char *argv[])
{
    int i = 0;
    const char key[] = "12345678";
    char data[100] = "12345678";

    des_encrypt(key, data, 8);
    
    putchar(data[0]);
/*    for (i = 0; i < 8; i++)
    {
        printf("%x", data[i]);
    }*/
    printf("\n");

    return EXIT_SUCCESS;
}
