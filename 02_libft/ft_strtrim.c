#include "libft.h"

int  checkset(char c, char const *set)
{
    int i;
    i = 0;
    while (set[i])
        if (c == set[i++])
            return 1;
    return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *ret;
    int     i;
    int     j;
    int     start;
    int     end;

    i = 0;

    while (checkset(s1[i], set))
        i++;

    start = i;
    i = ft_strlen(s1 - 1);

    while (checkset(s1[i], set))
        i--;

    end = i;

    i = end - start;
    ret = malloc(i + 1 + 1);
    i = start;
    j = 0;

    while (i <= end)
        ret[j++] = s1[i++];

    ret[j] = '\0';

    return ret;
}