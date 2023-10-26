#include "so_long.h"

void freeZ(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        void *ptr = va_arg(args, void*);
        if (!ptr)
            continue;
        free(ptr);
        ptr = NULL;
    }
}

void    map_cleaner(t_map *map)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (!map->tiles[i])
            continue;
        free(map->tiles[i]);
        map->tiles[i] = NULL;
    }

    free(map->tiles);
    map->tiles = NULL;

    free(map);
    map = NULL;
}

void     cleaner(t_data *data)
{
    mlx_destroy_image(data->display, data->bg->structure);
    mlx_destroy_image(data->display, data->coin_lyr->structure);
    mlx_destroy_image(data->display, data->player_lyr->structure);

    mlx_destroy_image(data->display, data->floor->structure);
    mlx_destroy_image(data->display, data->wall->structure);
    mlx_destroy_image(data->display, data->coin->structure);
    mlx_destroy_image(data->display, data->player->structure);
    mlx_destroy_image(data->display, data->stairs->structure);

    mlx_destroy_window(data->display, data->window);
    mlx_destroy_display(data->display);
    map_cleaner(data->map);

    freeZ(10, data->bg, data->coin_lyr, data->player_lyr, data->floor, data->wall, data->coin, data->player, data->stairs, 
            data->display, data);
}

int     frame_hdl(t_data *data);

int     key_hdl(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        cleaner(data);
        exit(0);
    }
    return 0;
}

int     destroy_hdl(t_data *data)
{
    cleaner(data);
    exit(0);
    return 0;
}
