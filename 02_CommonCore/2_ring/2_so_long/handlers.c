#include "so_long.h"


void freeZ(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        void *ptr = va_arg(args, void*);
        free(ptr)
    }
}

int     cleaner(t_data *data)
{
    mlx_destroy_image(data->display, data->canvas->structure);
    mlx_destroy_image(data->display, data->floor->structure);
    mlx_destroy_image(data->display, data->wall->structure);
    mlx_destroy_image(data->display, data->coin->structure);
    mlx_destroy_image(data->display, data->player->structure);
    mlx_destroy_image(data->display, data->exit->structure);

    mlx_destroy_window(data->display, data->window);
    mlx_destroy_display(data->display);

    freeZ(8, data->canvas, data->floor, data->wall, data->coin, data->player, data->exit, 
            data->display, data);

    return 0;
}


int     handler_key(int keysym, t_data *data)
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
}
