#include "ft.h"

int     main(int argc, char **argv)
{
    char  *ERR_MSG_NOARG = "File name missing";
    char  *ERR_MSG_MOARG = "Too many arguments";
    char  *ERR_MSG_NORD = "Cannot read file";
    int   BUFFER_SIZE = 1024;

    if (argc < 1)
        ft_putstr(ERR_MSG_NOARG);

    if (argc > 1)
        ft_putstr(ERR_MSG_MOARG);

    int         fd;
    char        buffer[BUFFER_SIZE];
    int         cursor;

    fd = open(argv[1], 0);

    while ((cursor = read(fd, buffer, BUFFER_SIZE)) > 0)
        write(1, buffer, cursor);

    if (cursor == -1)
        ft_putstr(ERR_MSG_NORD);

    close(fd);

    return 0;
}