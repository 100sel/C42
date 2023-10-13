#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    if (!ft_strlen(s))
        return;
    else 
        write(fd, s, ft_strlen(s)); 
    return;
}