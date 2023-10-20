#include "libft.h"

char *ft_strdup(const char *s)
{
    int     ss;
    char    *p;
    int     i;

    ss  = ft_strlen(s);
    p   = malloc((ss * sizeof(char)) + 1);
    i   = 0;

    while (i < ss)
    {
        p[i] = s[i];
        i++;
    }

    p[i] = 0;

    return p;
}