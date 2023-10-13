#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    if (!ft_strlen(s))
        write(fd, "\0", 1);
    else
        write(fd, s, ft_strlen(s));
    write(fd, "\n", 1);
    return;
}