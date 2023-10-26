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
            sprite = data->coin;
            draw_sprite(canvas, sprite, x * SPRITE_RES, y * SPRITE_RES,
                    sprite->width, sprite->height);  
            break;

        case 'P':
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
}

void    draw_bg(t_data *data)
{
    for (int y = 0; y < data->map->height / SPRITE_RES; y++)
    {
        for (int x = 0; x < data->map->width / SPRITE_RES; x++)
        {
            t_tile  *tile = &data->map->tiles[y][x];
            char    old_type = 0;

            if (tile->type == 'P' || tile->type == 'C')
            {
                old_type = tile->type;
                tile->type = '0';
            }

            draw_tile(data->bg, data, x, y);
            tile->type = old_type;
        }
    }
}

void    draw_coin_lyr(t_data *data)
{
    for (int y = 0; y < data->map->height / SPRITE_RES; y++)
        for (int x = 0; x < data->map->width / SPRITE_RES; x++)
        {
            t_tile  *tile = &data->map->tiles[y][x];
            if (tile->type == 'C')
                draw_tile(data->bg, data, x, y);
        }
}

void    draw_player_lyr(t_data *data)
{
    for (int y = 0; y < data->map->height / SPRITE_RES; y++)
        for (int x = 0; x < data->map->width / SPRITE_RES; x++)
        {
            t_tile  *tile = &data->map->tiles[y][x];
            if (tile->type == 'P')
                draw_tile(data->bg, data, x, y);
        }
}
/*
void    draw_bg(t_image *image, t_image *sprite, int width, int height)
{
    int  pixel;
    int  y_counter;
    int  x_counter;

    y_counter = 0;
    x_counter = 0;

    for (int y = 0; y < HEIGHT; ++y)
    {
        if (y_counter >= height)
            y_counter = 0;

        for (int x = 0; x < WIDTH; ++x)
        {
            if (x_counter >= width)
                x_counter = 0;

            pixel = pixel_get(sprite, x_counter, y_counter);
            pixel_put(image, x, y, pixel); 
            x_counter++;
        }
        y_counter++;
    }
}

void    draw_player(t_image *image, t_image *sprite, int width, int height)
{
    unsigned int pixel;
    int x_cnt;
    int y_cnt;

    x_cnt = 0;
    y_cnt = 0;

    for (int y = WIDTH / 2; y_cnt < height; ++y)
    {
        for (int x = HEIGHT / 2; x_cnt < width; ++x)
        {
            pixel = pixel_get(sprite, x_cnt, y_cnt);
            if (pixel != 0xFF000000)
                pixel_put(image, x, y, pixel); 
            x_cnt++;
        }
        x_cnt = 0;
        y_cnt++;
    }
}
*/

