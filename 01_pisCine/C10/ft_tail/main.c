#include "ft.h"
#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

int     file_size(char *file)
{
    int     total_size;
    int     cursor;
    int     BUFFER_SIZE = 24000;
    char    buffer[BUFFER_SIZE];
    int     fd;
    total_size = 0;
    fd = open(file, 0);
    while( (cursor = read(fd, buffer, BUFFER_SIZE)) > 0)
        total_size = total_size + cursor;
    return total_size;
}

int     main(int argc, char **argv)
{
    printf("%d\n", argc);
    int     BUFFER_SIZE = 24000;
    int     SIZE = atoi(argv[2]);
    char    *NAME = argv[3];
    int     FILE_SIZE = file_size(NAME);
    char    buffer[BUFFER_SIZE];
    int     fd;
    char    ret[SIZE + 1];

    fd = open(NAME, 0);

    read(fd, buffer, FILE_SIZE - SIZE);
    read(fd, ret, SIZE);
    write(1, ret, SIZE);

    return 0;
}