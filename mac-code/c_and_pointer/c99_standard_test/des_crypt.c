#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <rpc/des_crypt.h>
#include <sys/stat.h>
#include <sys/types.h>


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
    int fin, fout1, fout2;
    const char key[] = "12345678";
    char *data = NULL;
    struct stat st;

    fin = open("pragma.c", O_RDONLY);
    if (fin < 0)
    {
        fprintf(stderr, "open pragma.c failure\n");
        return EXIT_FAILURE;
    }

    fstat(fin, &st);
    data = (char *)malloc(st.st_size + 8);

    read(fin, data, st.st_size);

    des_encrypt(key, data, st.st_size);

    show(data, 10)
    
    return EXIT_SUCCESS;
}
