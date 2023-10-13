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
    int     i;
    int     j;
    int     k;
    int     start;
    int     count_s;
    char    **arr_p_s;

    i       = 0;
    count_s = 0;

    while (s[i])
    {
        while(s[i] && s[i] == c)
            i++;
        if (s[i] != c)
            count_s++;
        while (s[i] && s[i] != c)
            i++;
    }

    arr_p_s = malloc(sizeof(char *) * (count_s + 1) );
    i       = 0;
    j       = 0;

    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            arr_p_s[j] = malloc(i - start + 1);

            k = start;
            while (k < i)
            {
                arr_p_s[j][k - start] = s[k]; 
                k++;
            } 
            arr_p_s[j][k - start] = '\0';
            j++;
        }
    }
    arr_p_s[j] = "\0";

    return arr_p_s;
}