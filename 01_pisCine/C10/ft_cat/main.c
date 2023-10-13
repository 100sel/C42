#include "ft.h"
#include <libgen.h>
#include <errno.h>

int     main(int argc, char **argv)
{
    int     BUFFER_SIZE = 24000;
    int     cursor;
    int     fd;
    char    buffer[BUFFER_SIZE];

    if (argc != 2)
    {
        while ((cursor = read(0, buffer, BUFFER_SIZE)) > 0)
            write(1, buffer, cursor);
        return 0;
    }

    char    *file_name = basename(argv[1]);

    fd = open(file_name, 0);

    if (fd == -1)
        write(2, strerror(errno), ft_strlen(strerror(errno)));

    while ((cursor = read(fd, buffer, BUFFER_SIZE)) > 0)
        write(1, buffer, cursor);

    return 0;
}