#include "libft.h"

int power(int n, int p)
{
    int k;
    int ret;
    k = 0;
    ret = 1;
    while (k++ < p - 1)
        ret *= n;
    return ret;
};

int ft_atoi(const char *s)
{
    int size;
    int res;
    int i;
    int j;

    size = ft_strlen(s);
    res = 0;
    i = 0;
    j = size;

    if (s[0] == *"-" || s[0] == *"+")
    {
        i++;
        size -= 1;
    }
    else if (!ft_isdigit(s[0]))
        return 0;

    while (i < size)
    {
        if (!ft_isdigit(s[i]))
            return 0;

        res += (int)(s[i++]) * (power(10, j));
    }

    if (s[0] == *"-")
        res *= -1;

    return res;
}