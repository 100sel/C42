#include "libft.h"

char *ft_itoa(int n)
{
    char    *ret;
    int     nbr;
    char    neg;
    int     b[11];
    int     i;
    int     j;

    if (n >= 0)
    {
        neg = '\0';
        nbr = n;
    }
    else 
    {
        neg = '-';
        nbr = n * -1;   
    }

    i = 0;

    while (n)
    {
        b[i++] = nbr % 10;
        nbr /= 10;
    }

    if (neg)
        i++;

    ret = malloc(sizeof(char) * (i + 1));
    j = 0;

    if (neg)
    {
        ret[j++] = neg;
    }

    while (i > 0)
    {
        ret[j++] = b[--i] + '0';
    }

    ret[j] = '\0';
    return ret;
}