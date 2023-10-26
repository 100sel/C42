#include "so_long.h"

t_data  *get_assets(t_map *map)
{
    void    *display = NULL;
    void    *window = NULL;
    t_data  *data = NULL;
    t_image *bg = NULL;
    t_image *floor = NULL;
    t_image *wall = NULL;
    t_image *coin = NULL;
    t_image *player = NULL;
    t_image *stairs = NULL;

    char    *path_floor = "./textures/floor.xpm";
    char    *path_wall= "./textures/wall.xpm";
    char    *path_coin = "./textures/coin.xpm";
    char    *path_player = "./textures/player.xpm";
    char    *path_stairs = "./textures/stairs.xpm";

    int width;
    int height;

    width = map->width;
    height = map->height;

    data = malloc(sizeof(t_data));
    bg = malloc(sizeof(t_image));    
    floor = malloc(sizeof(t_image));
    wall = malloc(sizeof(t_image));
    coin = malloc(sizeof(t_image));
    player = malloc(sizeof(t_image));
    stairs = malloc(sizeof(t_image));

    display  = mlx_init();
    if (!display)
    {
        freeZ(7, data, bg, floor, wall, coin, player, stairs);
        exit(ERROR_);
    }

    window   = mlx_new_window(display, width, height, NAME);
    if (!window)
    {
        mlx_destroy_display(display);
        freeZ(8 ,bg, floor, wall, coin, player, stairs, display, data);
        exit(ERROR_);
    }

    make_layer(display, bg, width, height); 
    get_sprite(display, path_floor, floor); 
    get_sprite(display, path_wall, wall); 
    get_sprite(display, path_coin, coin); 
    get_sprite(display, path_player, player); 
    get_sprite(display, path_stairs, stairs); 

    data->display   = display;
    data->window    = window;
    data->bg        = bg;
    data->floor     = floor;
    data->wall      = wall;
    data->coin      = coin;
    data->player    = player;
    data->stairs    = stairs;
    data->map       = map;
    data->move_cnt  = 0;

    return data;
}

