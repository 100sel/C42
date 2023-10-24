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
}           t_image;


typedef struct s_data {
    void    *display;
    void    *window;
    t_image *image;
}           t_data;





int     encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}


void    ft_pixel_put(t_image *image, int x, int y, int color)
{
    int offset;
    offset = (y * image->line_length) + (x * (image->bits_per_pixel / 8));

    *((unsigned int *)(image->pixels + offset)) = color;
}


void    drawer(t_data *data, int color)
{
    int start = WIDTH / 2 - 1;
    int end = WIDTH / 2 + 1;

    for (int y = HEIGHT * 0.1; y < HEIGHT; ++y)
    {
        if (y < HEIGHT / 2)
        {
        for (int x = start; x < end; ++x)
            ft_pixel_put(data->image, x, y, color); 
        start--;
        end++;
        }
        else 
        {
        for (int x = start; x < end ; ++x)
            ft_pixel_put(data->image, x, y, color);
        start++;
        end--;
        }
    }
}





int     cleaner(t_data *data)
{
    mlx_destroy_window(data->display, data->window);
    mlx_destroy_display(data->display);
    free(data->image->pixels);
    free(data->image);
    free(data->display);
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





int     main(void)
{
    void    *display;
    void    *window;
    t_data  data;
    t_image image;

    display  = mlx_init();
    if (!display)
        return MALLOC_ERROR;

    window   = mlx_new_window(display, WIDTH, HEIGHT, NAME);
    if (!window)
    {
        mlx_destroy_display(display);
        free(display);
        return MALLOC_ERROR;
    }

    image.structure = mlx_new_image(display, WIDTH, HEIGHT);
    image.pixels    = mlx_get_data_addr(image.structure, 
            &image.bits_per_pixel, &image.line_length, &image.endian);

    data.display    = display;
    data.window     = window;
    data.image      = &image;

    mlx_key_hook(window, handler_key, &data);
    mlx_hook(window, 17, (1L<<17), destroy_hdl, &data);
    drawer(&data, encode_rgb(0, 255, 0));
    mlx_put_image_to_window(display, window, image.structure, 0, 0);

    mlx_loop(display);

    cleaner(&data);

    return 0;
}
