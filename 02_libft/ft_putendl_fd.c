#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    const char  endl = '\n';
    write(fd, s, ft_strlen(s));
    write(fd, &endl, 1);
    return;
}