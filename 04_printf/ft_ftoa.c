#include "libft.h"

char *ft_ftoa(float f, int prec)
{
    char    *ret;
    char    *b;
    char    *ent;
    float   dec;
    int     i;

    if (f < 0)
        f = -f;

    ret = malloc(39);
    ent = ft_itoa((int)f);
    dec = f - (int)f;
    b   = ret;
    i   = 0;

    while (*ent)
        *b++ = *ent++;
    *b++ = '.';

    while (i++ < prec)
    {
        *b++ = (int)(dec * 10) + '0';
        dec *= 10;
        dec = dec - (int)dec;
    }
    *b = '\0';

    free(ent);
    return ret;
}