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

void    draw_tile(t_data *data, int x, int y)
{
    switch (data->map->tiles[y][x].type)
    {
        case '0':

            break;

        case '1':

            break;

        case 'C':

            break;

        case 'P':
            printf("There is a player !");
            draw_sprite(data->canvas, data->player, 
                    x * SPRITE_RES, y * SPRITE_RES, data->player->width, data->player->height);  
            break;

        case 'E':

            break;

        default:
            break;
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

