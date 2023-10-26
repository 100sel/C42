#include <mlx.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define ERROR_          1
#define NAME            "so_long"
#define MAX_SIZE        256
#define SPRITE_RES      15

typedef unsigned char byte;

typedef struct s_tile {
    char type;
    int x;
    int y;
    int visited;
}               t_tile;

typedef struct s_map {
    t_tile **tiles;
    int width;
    int height;
}               t_map;

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
    t_image *bg;
    t_image *coin_lyr;
    t_image *player_lyr;
    t_image *floor;
    t_image *wall;
    t_image *coin;
    t_image *player;
    t_image *stairs;
    t_map   *map;
}               t_data;

t_data          *get_assets(int width, int height);

void            freeZ(int count, ...);
void            cleaner(t_data *data);
void            map_cleaner(t_map *map);

int             type_valid(char type);
t_map           *get_map(char *path);
int             find_exit(t_map *map, int x, int y);

unsigned int    pixel_get(t_image *img, int x, int y);
void            pixel_put(t_image *image, int x, int y, unsigned int pixel); 
void            get_sprite(void *display, char *path, t_image *sprite);
void            make_layer(void *display, t_image *layer, int x, int y);
void            draw_sprite(t_image *canvas, t_image *sprite, 
        int x_start, int y_start, int width, int height);
void            draw_tile(void *display, t_data *data, int x, int y);
void            draw_bg(t_data *data);
void            draw_coin_lyr(t_data *data);
void            draw_player_lyr(t_data *data);

int             frame_hdl(t_data *data);
int             key_hdl(int keysym, t_data *data);
int             destroy_hdl(t_data *data);

