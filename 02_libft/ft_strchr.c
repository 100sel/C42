#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    int     i;
    int     ss;
    char    *p;

    ss  = ft_strlen(s);
    i   = 0;
    p   = 0;

    while (i < ss)
    {
        if (s[i] == c)
        {
            p = (char *)(s + i);
            return p;
        }
        i++;
    }

    return p;
}