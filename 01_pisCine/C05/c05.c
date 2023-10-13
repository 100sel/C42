#include <stdio.h>

int     ft_iterative_factorial(int nb) {
    int r;

    r = nb;

    while (nb > 1)
        r = r * --nb;

    return r;
}

int     ft_iterative_power(int nb, int power) {
    int r;
    int i;

    r = power;
    i = 0;
    while (i < power - 1) {
        r = r * power;
        i++; 
    }
    return r;
}

int     ft_recursive_factorial(int nb) {
    int r;

    if (nb == 1)
        return nb;
    
    r = nb * ft_recursive_factorial(nb - 1);

    return r;
}

int     ft_recursive_power(int nb, int power) {
    int r;

    if (power == 1)
        return nb;
    
    r = nb * ft_recursive_power(nb, power - 1);

    return r;
}

int     ft_fibonacci(int index) {
    if (index < 0)
        return -1;

    int r;

    if (index == 0)
        return 0;

    if (index == 1)
        return 1;
    
    r = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);

    return r;
}

int     ft_sqrt(int nb) {
    int i;
    int r;

    i = 0;

    while (i < nb) {
        r = i * i;

        if (r == nb)
            return i;
        i++;    
    }        

    return 0;
}

void    main() {

}