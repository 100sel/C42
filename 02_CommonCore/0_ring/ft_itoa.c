#include "libft.h"

char *ft_itoa(int n)
{
    char *ret;
    long int nbr;
    char neg;
    int b[10];
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
        nbr = (long int)n * -1; 
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

    ret = malloc(sizeof(char) * (i + 1 + 1));
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