#include "so_long.h"

int     encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}

void get_sprite(void *display, char *path, t_image *sprite)
{
    sprite->structure    = mlx_xpm_file_to_image(display, path, &sprite->width, &sprite->height);
    sprite->pixels       = mlx_get_data_addr(sprite->structure, 
            &sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
}

void make_layer(void *display, t_image *layer, int width, int height)
{
    layer->structure = mlx_new_image(display, width, height);
    layer->pixels    = mlx_get_data_addr(layer->structure, 
            &layer->bits_per_pixel, &layer->line_length, &layer->endian);
}

void    pixel_put(t_image *image, int x, int y, unsigned int pixel)
{
    int offset;
    offset = (y * image->line_length) + (x * (image->bits_per_pixel / 8));

    *(int *)(image->pixels + offset) = pixel;
}

unsigned int   pixel_get(t_image *img, int x, int y)
{
    int offset;

    offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
    return *(unsigned int *)(img->pixels + offset);
}

void    draw_sprite(t_image *canvas, t_image *sprite, int x_start, int y_start, int width, int height)
{
    unsigned int pixel;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            pixel = pixel_get(sprite, x, y);
            if (pixel != 0xFF000000)
                pixel_put(canvas, x + x_start, y + y_start, pixel); 
        }
    }
}

void    draw_tile(void *canvas, t_data *data, int x, int y)
{
    t_image *sprite = NULL;
    switch (data->map->tiles[y][x].type)
    {
        case '0':
            sprite = data->floor;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);  
            break;

        case '1':
            sprite = data->wall;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);  
            break;

        case 'C':
            sprite = data->floor;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);
            sprite = data->coin;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);  
            break;

        case 'P':
            sprite = data->floor;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);
            sprite = data->player;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);  
            break;

        case 'E':
            sprite = data->stairs;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);  
            break;

        default:
            break;
    }
    data->map->tiles[y][x].dirty = 0;
}

int     render(t_data *data)
{
    int new = 0;
    for (int y = 0; y < data->map->height / SPRITE_RES; y++)
        for (int x = 0; x < data->map->width / SPRITE_RES; x++)
            if (data->map->tiles[y][x].dirty)
            {
                draw_tile(data->bg, data, x, y);
                new++;
            }
    return new;
}
