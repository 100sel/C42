#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *ret;
    int     i;

    ret = malloc(ft_strlen(s) + 1);
    i   = 0;

    while (s[i])
    {
        ret[i] = f(i, s[i]);
        i++;
    }

    ret[i] = '\0';
    return ret;
}