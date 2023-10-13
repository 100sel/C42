#include <unistd.h>

void    main(int argc, char **argv) {
    int i;
    char *b;
    i = 0;
    while (argv[0][i] != 0) {
        if (argv[0][i] == *("\\"))
            b = argv[0] + i;
        i++;
    } 
    write(1, "./", 2);
    i = 1;
    while (b[i] != 0) {
        write(1, b + i, 1);
        i++;
    }
    write(1, "\n", 1);
}