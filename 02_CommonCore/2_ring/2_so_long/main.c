#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR    1
#define WIDTH           1280
#define HEIGHT          720
#define NAME            "so_long"



typedef unsigned char byte;


typedef struct s_image {
    void *structure;
    char *pixels;
    int  bits_per_pixel;
    int  line_length;
    int  endian;
    int  width;
    int  height;
}           t_image;


typedef struct s_data {
    void    *display;
    void    *window;
    t_image *image;
    t_image *bg;
    t_image *player;
}           t_data;





int     encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}


void    pixel_put(t_image *image, unsigned int x, int y, int pixel)
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





int     cleaner(t_data *data)
{
    mlx_destroy_image(data->display, data->image->structure);
    mlx_destroy_image(data->display, data->bg->structure);
    mlx_destroy_image(data->display, data->player->structure);

    mlx_destroy_window(data->display, data->window);
    mlx_destroy_display(data->display);

    free(data->image);
    free(data->bg);
    free(data->player);

    free(data->display);
    free(data);

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





t_data  *init(void)
{
    void    *display;
    void    *window;
    t_data  *data;
    t_image *image;
    t_image *bg;
    t_image *player;
    char    *path_bg = "./textures/floor.xpm";
    char    *path_player = "./textures/player.xpm";

    data = malloc(sizeof(t_data));
    image = malloc(sizeof(t_image));    
    bg = malloc(sizeof(t_image));
    player = malloc(sizeof(t_image));

    display  = mlx_init();
    if (!display)
    {
        free(data);
        free(image);
        free(bg);
        free(player);
        exit(MALLOC_ERROR);
    }

    window   = mlx_new_window(display, WIDTH, HEIGHT, NAME);
    if (!window)
    {
        free(data);
        free(image);
        free(bg);
        free(player);
        mlx_destroy_display(display);
        free(display);
        exit(MALLOC_ERROR);
    }

    image->structure = mlx_new_image(display, WIDTH, HEIGHT);
    image->pixels    = mlx_get_data_addr(image->structure, 
            &image->bits_per_pixel, &image->line_length, &image->endian);
     
    bg->structure    = mlx_xpm_file_to_image(display, path_bg, &bg->width, &bg->height);
    bg->pixels       = mlx_get_data_addr(bg->structure, 
            &bg->bits_per_pixel, &bg->line_length, &bg->endian);


    player->structure    = mlx_xpm_file_to_image(display, path_player, &player->width, &player->height);
    player->pixels       = mlx_get_data_addr(player->structure, 
            &player->bits_per_pixel, &player->line_length, &player->endian);

    data->display    = display;
    data->window     = window;
    data->image      = image;
    data->bg         = bg;
    data->player     = player;

    draw_bg(image, bg, bg->width, bg->height);
    draw_player(image, player, player->width, player->height);

    return data;
}





int     main(void)
{
    t_data *data= init();

    mlx_key_hook(data->window, handler_key, data);
    mlx_hook(data->window, 17, (1L<<17), destroy_hdl, data);

    mlx_put_image_to_window(data->display, data->window, data->image->structure, 0, 0);
    mlx_loop(data->display);

    cleaner(data);

    return 0;
}
