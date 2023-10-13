#include "libft.h"

char *ft_itoa(int n)
{
    char *ret;
    int nbr;
    char neg;
    int b[11];
    int i;
    int j;

    if (n >= 0)
    {
        neg = '\0';
        nbr = n;
    }
    else
    {
        neg = '-';
        nbr = -n; 
    }

    i = 0;

    if (nbr == 0)
        b[i++] = 0;
    else
    {
        while (nbr)
        {
            b[i++] = nbr % 10;
            nbr /= 10;
        }
    }

    ret = malloc(sizeof(char) * (i + 1));
    j = 0;

    while (i > 0) 
    {
        if (neg && j == 0)
            ret[j++] = neg;
        else
            ret[j++] = b[--i] + '0';
    }

    ret[j] = '\0';
    return ret;
}