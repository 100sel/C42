#include "so_long.h"

t_data  *init_data(void)
{
    void    *display;
    void    *window;
    t_data  *data;

    t_image *canvas;
    t_image *floor;
    t_image *wall;
    t_image *coin;
    t_image *player;
    t_image *stairs;

    char    *path_floor = "./textures/floor.xpm";
    char    *path_wall= "./textures/wall.xpm";
    char    *path_coin = "./textures/coin.xpm";
    char    *path_player = "./textures/player.xpm";
    char    *path_stairs = "./textures/stairs.xpm";

    data = malloc(sizeof(t_data));
    canvas = malloc(sizeof(t_image));    
    floor = malloc(sizeof(t_image));
    wall = malloc(sizeof(t_image));
    coin = malloc(sizeof(t_image));
    player = malloc(sizeof(t_image));
    stairs = malloc(sizeof(t_image));

    display  = mlx_init();
    if (!display)
    {
        freeZ(7, data, canvas, floor, wall, coin, player, stairs);
        exit(MALLOC_ERROR);
    }

    window   = mlx_new_window(display, WIDTH, HEIGHT, NAME);
    if (!window)
    {
        mlx_destroy_display(display);
        freeZ(8,canvas, floor, wall, coin, player, stairs, display, data);
        exit(MALLOC_ERROR);
    }

    canvas->structure = mlx_new_image(display, WIDTH, HEIGHT);
    canvas->pixels    = mlx_get_data_addr(canvas->structure, 
            &canvas->bits_per_pixel, &canvas->line_length, &canvas->endian);

    get_sprite(display, path_floor, floor); 
    get_sprite(display, path_wall, wall); 
    get_sprite(display, path_coin, coin); 
    get_sprite(display, path_player, player); 
    get_sprite(display, path_stairs, stairs); 

    data->display   = display;
    data->window    = window;
    data->canvas    = canvas;
    data->floor     = floor;
    data->wall      = wall;
    data->coin      = coin;
    data->player    = player;
    data->stairs    = stairs;

    return data;
}

