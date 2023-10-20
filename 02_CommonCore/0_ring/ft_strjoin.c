#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int     size_s1;
    int     size_s2;
    char    *ret;
    int     i;
    int     j;

    size_s1 = ft_strlen(s1);
    size_s2 = ft_strlen(s2);
    ret = malloc(size_s1 + size_s2 + 1);
    i = 0;

    j = 0;
    while (j < size_s1)
        ret[i++] = s1[j++];

    j = 0;
    while (j < size_s2)
        ret[i++] = s2[j++];

    ret[i] = '\0';
    return ret;
}