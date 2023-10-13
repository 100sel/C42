#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
    int     i;
    int     j;
    int     k;

    i   = 0;
    j   = 0;

    while (i < (int)n && s1[i])
    {
        if (s1[i] == s2[j])
        {
            k = i;

   
            while (s1[k++] == s2[j++])
            {
                if (!s2[j])
                    return (char *)(s1 + i);
            }

            k = 0;
            j = 0;
        }
        i++;
    }

    return 0;
}