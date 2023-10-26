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
    mlx_destroy_image(data->display, data->floor->structure);
    mlx_destroy_image(data->display, data->wall->structure);
    mlx_destroy_image(data->display, data->coin->structure);
    mlx_destroy_image(data->display, data->player->structure);
    mlx_destroy_image(data->display, data->stairs->structure);

    mlx_destroy_window(data->display, data->window);
    mlx_destroy_display(data->display);
    map_cleaner(data->map);

    freeZ(8, data->bg, data->floor, data->wall, data->coin, data->player, data->stairs, 
            data->display, data);
}

int     frame_hdl(t_data *data)
{
    if (render(data))
        mlx_put_image_to_window(data->display, data->window, data->bg->structure, 0, 0);

    return 0;
}

void    move_hdl(char dir, t_data *data)
{
    t_map  *map;
    t_tile *old_pos;
    t_tile *new_pos;

    map = data->map;
    old_pos = data->map->player;

    switch(dir) 
    {
        case 'z': 
                new_pos = &map->tiles[map->player->y - 1][map->player->x];
            break;

        case 'q':
                new_pos = &map->tiles[map->player->y][map->player->x - 1];
            break;

        case 's':
                new_pos = &map->tiles[map->player->y + 1][map->player->x];
            break;

        case 'd':
                new_pos = &map->tiles[map->player->y][map->player->x + 1];
            break;

        default:
            break;
    }
    
    if (new_pos->type == '1')
        return;

    printf("%d\n", ++data->move_cnt);

    if (new_pos->type == 'E' && !map->coins)
    {
        cleaner(data);
        exit(0);
    }

    if (new_pos->type == 'C')
        map->coins--;

    new_pos->type  = 'P';
    new_pos->dirty = 1;

    old_pos->type  = '0';
    old_pos->dirty = 1;

    map->player = new_pos;
}

int     key_hdl(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        cleaner(data);
        exit(0);
    }

    if (keysym == XK_z)
        move_hdl('z', data);
    if (keysym == XK_q)
        move_hdl('q', data);
    if (keysym == XK_s)
        move_hdl('s', data);
    if (keysym == XK_d)
        move_hdl('d', data);
    return 0;
}

int     destroy_hdl(t_data *data)
{
    cleaner(data);
    exit(0);
    return 0;
}
