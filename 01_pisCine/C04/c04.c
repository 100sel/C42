#include <unistd.h>

int     ft_strlen(char *str) {
    int i;

    i   = 0;

    while (str[i] != 0)
        i++;
    
    return i;
}

void    ft_putstr(char *str) {
    int i;

    i   = 0;

    while (str[i] != 0)
        write(1, str + i++, 1);
}

void    ft_putnbr(int nb) {
    int     b[11];
    char    r[11];
    int     i;
    int     j;

    i   = 0;
    j   = 0;

    while (nb / 10 > 1) {
        b[i] = nb % 10;
        nb = nb / 10;
        i++;
    }
    b[i] = nb;

    while (i >= 0) {
        r[j] = b[i] + 48;
        i--;
        j++;
    }
    r[j] = 0;    

    ft_putstr(r);
}

void    main() {
    ft_putnbr(543210);
}