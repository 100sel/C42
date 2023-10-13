#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    if (!ft_strlen(s))
        write(fd, "\0", 1);
    write(fd, s, ft_strlen(s)); 
    return;
}