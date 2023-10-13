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
    int res;
    int i;
    int j;

    res = 0;
    i = 0;
    j = ft_strlen(s) - 1;

    if (s[0] == '-' || s[0] == '+')
    {
        i++;
        j--;
    }
    else if (!ft_isdigit(s[0]))
        return 0;

    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return 0;

        res += (int)(s[i++] - '0') * (power(10, j--));
    }

    if (s[0] == '-')
        res *= -1;

    return res;
}