#include "so_long.h"

int     main(void)
{
    t_data *data= init_data();

    mlx_key_hook(data->window, handler_key, data);
    mlx_hook(data->window, 17, (1L<<17), destroy_hdl, data);
    
    draw_sprite(data->canvas, data->player, 
            WIDTH / 2, HEIGHT / 2, data->player->width, data->player->height);  

    mlx_put_image_to_window(data->display, data->window, data->canvas->structure, 0, 0);
    mlx_loop(data->display);

    cleaner(data);

    return 0;
}
