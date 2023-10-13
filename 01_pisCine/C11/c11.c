#include <stdio.h>
#include <stdlib.h>

void    ft_foreach(int *tab, int length, void(*f)(int))
{
    int i = 0;
    while (i < length)
        f(tab[i++]);
}   

int     *ft_map(int *tab, int length, int(*f)(int))
{
    int *ret = malloc(length * sizeof tab[0]);
    int i = 0;

    while (i < length)
    {
        ret[i] = f(tab[i]);
        i++;
    }

    return ret;
}

int     ft_any(char *tab, int(*f)(char*))
{

}

void    ft_putint(int v)
{
    printf("%d", v);
}

int    ft_timestwo(int v)
{
    return v * 2;
}

int     main(void)
{
    int tab[5] = {1, 2, 3, 4, 5};
    int *tab2 = ft_map(tab, 5, &ft_timestwo);
    ft_foreach(tab2, 5, &ft_putint);
}