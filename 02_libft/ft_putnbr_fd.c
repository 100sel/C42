#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char *nbr = ft_itoa(n);
    write(fd, nbr, ft_strlen(nbr));
    free(nbr); 
    return;
}