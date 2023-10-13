#include "ft_stock_str.h"

void     ft_putstr(char *str)
{
    int     i;

    i = 0;

    while(str[i])
    {
        write(1, str + i, 1);
        i++;
    }
    write(1, "\n", 1);
}

void    ft_putnbr(int nbr) 
{
    int    buf[11];
    char    res[11];
    int     i;
    int     j;

    i = 0;
    while(nbr / 10 > 1)
    {
        buf[i] = nbr % 10;
        nbr = nbr / 10;
        i++;
    }
    buf[i] = nbr;

    j = 0;
    while(i >= 0)
    {
        res[j] = buf[i] + 48;
        i--;
        j++;
    }
    res[j] = 0;
    
    ft_putstr(res);
}

int     ft_strlen(char *str) 
{
    int     i;

    i = 0;

    while (str[i])
        i++;

    return i;
}

char    *ft_strcpy(char *str)
{
    int     i;
    int     size;
    char    *r;

    i = 0;
    size = ft_strlen(str);
    r = malloc(size + 1 * 1);

    while (str[i]) 
    {
        r[i] = str[i];
        i++;
    }

    r[i] = 0;
    return r;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av) 
{
    int     i;
    t_stock_str *r;

    i = 0;
    r = malloc(sizeof(t_stock_str) * ac + 1);

    while (i < ac)
    {
        r[i].size = ft_strlen(av[i]);
        r[i].str = av[i];
        r[i].copy = ft_strcpy(av[i]);
        i++;
    }
    r[i].str = 0;
    return r;
}

void    ft_show_tab(struct s_stock_str *par)
{
    int     i;

    i = 0;

    while(par[i].str)
    {
        ft_putstr(par[i].str);
        ft_putnbr(par[i].size);
        ft_putstr(par[i].copy);
        i++;
    }
}

int     main(void) 
{
    char            *strs[] = {"bitch", "testing", "this", "shit"};
    t_stock_str     *tab = ft_strs_to_tab(4, strs);
    ft_show_tab(tab);
    return(0);
}