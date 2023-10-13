#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len) 
{
    if (start > (unsigned int) len)
        return "\0";

    char    *ret;
    int     i;
    int     j;

    ret = malloc(len + 1);
    i = start;
    j = 0;

    while (s[i])
        ret[j++] = s[i++];

    ret[j] = '\0';
    return ret;
}