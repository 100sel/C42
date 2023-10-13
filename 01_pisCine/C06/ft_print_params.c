#include <unistd.h>

void    main(int argc, char **argv) {
    int     i;
    i   = 1;

    while (i <= argc) {
        int     j;
        j   = 0;
        while (argv[i][j] != 0) {
            write(1, argv[i] + j, 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}