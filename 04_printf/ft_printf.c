#include "libft.h"

int ft_printf(const char *str, ...) 
{
    va_list args;
    char    *ptr_str;
    int     count_perc;

    count_perc  = 0;
    ptr_str     = (char *)str;

    while (*ptr_str)
    {
        if (*ptr_str == '%')
        {
            count_perc++;
            ptr_str++;
            if (*ptr_str != '%')
                ptr_str++;
        } 
        else
            ptr_str++;
    }

    if (!count_perc)
    {
        write(1, str, ft_strlen(str));
        return 0;
    }
    
    va_start(args, str);
    ptr_str = (char *)str;

    while (*ptr_str)
    {
        if (*ptr_str != '%')
        {
            write(1, ptr_str++, 1);
            continue;
        }
        switch (*++ptr_str) 
        {
            case 'c': 
                char argc = va_arg(args, int);
                write(1, &argc, 1);
                break;
            case 's':
                char *argss = va_arg(args, char *);
                write(1, argss, ft_strlen(argss));
                break;
            case 'p':
                char *argp = ft_ptox(va_arg(args, void *));
                write(1, argp, 17);
                free(argp);
                break;
            case 'f':
                char *argf = ft_ftoa((float)(va_arg(args, double)), 2);
                write(1, argf, ft_strlen(argf));
                free(argf);
                break;
            case 'i':
                char *argi = ft_itoa(va_arg(args, int));
                write(1, argi, ft_strlen(argi));
                free(argi);
                break;
            case '%':
                char argpp = '%';
                write(1, &argpp, 1);
                break;
            default: 
                break;
        }
        ptr_str++;
    }

    return 0;
}

#include <stdio.h>
int main(void)
{
    int *n = malloc(1);
    n[0] = 42;
    ft_printf("testing %f\n", 42.42);
    printf("testing %f\n", 42.42);
    free(n);
    return 0;
}