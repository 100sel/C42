#include "libft.h"
/*
char **ft_split(char const *s, char c)
{
    char    **ret;
    int     i;
    int     j;
    int     k;
    int     size_s;
    int     count_c;
    int     *sizes;
    int     size_total;

    size_s = ft_strlen(s);
    i = 0;

    while (s[i] < size_s)
    {
        if (s[i] == c)
            i++;
        count_c = i;
    }
    
    if (count_c >= (int)ft_strlen(s))
        return 0;

    i = 0;
    j = 0;
    k = 0;
    sizes = malloc((count_c * sizeof(int)) + 1);

    while (s[i])
    {
        while (s[i++] != c)
            j++;
        if (j > 0)
            sizes[k++] = j;
        j = 0; 
    }

    sizes[k] = 0;
    i = 0;
    
    while (sizes[i])
        size_total += sizes[i++];

    free(sizes);
    ret = malloc(size_total + 1);

    i = 0;
    j = 0;

    while (s[i])
    {
        if (s[i] != c)
            *ret[j] = s[i];
        else 
            *ret[j] = '\0';
        j++;
        i++;
    }
    
    ret[j] = '\0';
    return ret;
}
*/
char **ft_split(char const *s, char c)
{
    int  i;
    int  j;
    int  count_ret;
    char **ret;

    count_ret   = 0;
    i           = 0;

    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c)
            count_ret++;
        i++;
    }

    ret = malloc(sizeof(char *) * (count_ret + 1));
    i   = 0;
    j   = 0;

    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c)
            ret[j++] = (char *)s + i + 1;
        i++;
    }
    ret[j] = 0;

    return ret;
}