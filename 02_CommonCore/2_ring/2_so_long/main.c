#include "so_long.h"

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("./%s path/to/map.ber", NAME);
        return ERROR_;
    }

    t_map   *map  = get_map(argv[1]);
    t_data  *data = get_assets(map->width, map->height);
    data->map     = map;

    mlx_key_hook(data->window, key_hdl, data);
    mlx_hook(data->window, 17, (1L<<17), destroy_hdl, data);
//    mlx_loop_hook(data->display, frame_hdl, data); 
    
    frame_hdl(data);
    mlx_put_image_to_window(data->display, data->window, data->canvas->structure, 0, 0);
    mlx_loop(data->display);

    cleaner(data);

    return 0;
}
