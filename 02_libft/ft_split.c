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
    //int  k;
    int  count_c;
    int  count_s;
    //int  count_total;
    char **arr_p_c;
    char **arr_p_s;
    //char *ret;

    i = 0;
    j = 0;

    while (s[i])
    {
        if (s[i] == c)
            count_c++;
        i++;
    }

    arr_p_c = malloc(sizeof(char *) * count_c + 1);
    i       = 0;

    while (s[i])
    {
        if (s[i] == c)
            arr_p_c[j++] = (char *)s + i;
        i++;
    }
    arr_p_c[j] = 0;

    i = 0;
    j = 0;

    while (arr_p_c[i])
    {
        if (*arr_p_c[i + 1] != c)
            count_s++;
        i++; 
    }

    arr_p_s = malloc(sizeof(char *) * count_s + 1);
    i       = 0;

    while (arr_p_c[i])
    {
        if (*arr_p_c[i + 1] != c)
            arr_p_s[j++] = arr_p_c[i + 1];
        i++;
    }
    arr_p_s[j] = 0;

    free(arr_p_c);
    return arr_p_s;
/*
    i = 0;
    j = 0;

    while (arr_p_s[i])
    {
        while (arr_p_s[i][j] != c)
        {
            count_total++;
            j++;
        }
        j = 0;
        i++;
    }

    ret = malloc( (count_s * sizeof(char)) + count_total * sizeof (char) ); 
    i = 0;
    j = 0;

    while (arr_p_s[i])
    {
        while(arr_p_s[i][j] != c)
        {
            ret[k++] = arr_p_s[i][j++]; 
        }
        ret[k++] = '\0';
        i++;
    }

    free(arr_p_s);
    return ret;
*/
}