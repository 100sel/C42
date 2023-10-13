#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    int i; 
    i = 0;
    char *nbr = ft_itoa(n);
    ft_putstr_fd(nbr, fd);
    while (nbr[i])
        free(nbr + i++); 
    return;
}