#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#include <unistd.h>
#include <fcntl.h>
#include <rpc/des_crypt.h>
#include <sys/stat.h>
#include <sys/types.h>


#define OUTFILE         "des_outfile"


static jmp_buf env;


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
    printf("\n");
}

static int openfile(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failure", filename);
        longjmp(env, 4);
    }

    return fd;
}

static long filelen(int fd)
{
    struct stat stat;

    fstat(fd, &stat);

    return stat.st_size;
}

void *dataspace(long int len)
{
    void *data = malloc(len);
    if (data == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        longjmp(env, 6);
    }

    return data;
}

static void closefile(int fd)
{
    close(fd);
}

static void get_input_info(unsigned char **data, long int *plen, const char *filename)
{
    int fd = 0;
    fd = openfile(filename);   
    *plen = filelen(fd);
    *data = dataspace(*plen+8);

    if (read(fd, *data, *plen) < 0)
    {
        fprintf(stderr, "read file failure\n");
        free(*data), *data = NULL;
        longjmp(env, 3);
    }

    closefile(fd);
}

static int create_outfile(const char *filename)
{
    int fd = 0;

    unlink(filename);

    fd = open(filename, O_CREAT|O_TRUNC|O_RDWR, 0777);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failure", filename);
        longjmp(env, 1);
    }

    return fd;
}

static void set_output_file(unsigned char *data, long int filelen)
{
    int fd = 0;

    fd = create_outfile("outfile.ko");
    if (write(fd, data, filelen) != filelen)
    {
        fprintf(stderr, "write failure\n");
        free(data), data = NULL;

        longjmp(env, 2);
    }

    free(data), data = NULL;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    unsigned char *pdata = NULL;
    long int filelen = 0;
    const char *key = "12345678";

    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./a.out filename1, ...\n");
        return EXIT_FAILURE;
    }

    if ((ret = setjmp(env)) == 0)
    {
        get_input_info(&pdata, &filelen, argv[1]);
        des_encrypt(key, pdata, filelen);
        set_output_file(pdata, filelen);
    }
    else
    {
        fprintf(stderr, "%d error\n", ret);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
