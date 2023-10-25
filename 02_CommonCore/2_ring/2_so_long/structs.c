#include "so_long.h"

typedef unsigned char byte;

typedef struct s_tile {
    char type;
    int x;
    int y;
}           t_tile;

typedef struct s_image {
    void *structure;
    char *pixels;
    int  bits_per_pixel;
    int  line_length;
    int  endian;
    int  width;
    int  height;
}           t_image;

typedef struct s_data {
    void    *display;
    void    *window;
    t_image *canvas;
    t_image *floor;
    t_image *wall;
    t_image *coin;
    t_image *player;
    t_image *exit;
}           t_data;

