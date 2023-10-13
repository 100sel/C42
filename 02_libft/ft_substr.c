#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len) 
{
    char    *ret;
    int     i;
    int     j;

    ret = malloc(len + 1);
    i = start;
    j = 0;

    if (start > ft_strlen(s))
    {
        ret[0] = '\0';
        return ret;
    }

    while (s[i] && j < (int)len)
        ret[j++] = s[i++];

    ret[j] = '\0';
    return ret;
}