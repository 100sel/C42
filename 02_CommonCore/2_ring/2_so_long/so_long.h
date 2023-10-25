#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR    1
#define WIDTH           1280
#define HEIGHT          720
#define NAME            "so_long"

typedef unsigned char byte;

typedef struct s_tile {
    char type;
    int x;
    int y;
}               t_tile;

typedef struct s_image {
    void *structure;
    char *pixels;
    int  bits_per_pixel;
    int  line_length;
    int  endian;
    int  width;
    int  height;
}               t_image;

typedef struct s_data {
    void    *display;
    void    *window;
    t_image *canvas;
    t_image *floor;
    t_image *wall;
    t_image *coin;
    t_image *player;
    t_image *exit;
}               t_data;

t_data          *init_data(void);

void            freeZ(int count, ...);
int             cleaner(t_data *data);

unsigned int    pixel_get(t_image *img, int x, int y);
void            pixel_put(t_image *image, int x, int y, unsigned int pixel); 
int             get_sprite(void *display, char *path, t_image *sprite);
void            draw_sprite(t_image *canvas, t_image *sprite, 
        int x_start, int y_start, int width, int height);

int             handler_key(int keysym, t_data *data);
int             destroy_hdl(t_data *data);

