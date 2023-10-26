#include "so_long.h"

int     type_valid(char type)
{
    char *types = "01CEP";

    while (*types)
        if (type == *types++)
            return 1;

    return 0;
}

t_map   *get_map(char *path)
{
    t_tile  **tiles = NULL;
    t_map   *map = NULL;
    char    buffer;
    int     fd;
    int     x;
    int     y;
    int     player_flag;
    int     stairs_flag;
    int     coin_flag;
    int     width;
    int     read_cnt;
    t_tile  *player_pos;
    int     err_flag;
    char    *err_msg = NULL;

    x           = 0;
    y           = 0;
    player_flag = 0;
    stairs_flag = 0;
    coin_flag   = 0;
    err_flag    = 0;
    map         = malloc(sizeof(t_map));
    tiles       = calloc(MAX_SIZE, sizeof(t_tile));

    for (int i = 0; i < MAX_SIZE; i++)
        tiles[i] = calloc(MAX_SIZE, sizeof(t_tile));

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        err_flag++;
        err_msg = "Error opening tiles";
    }

    while(!err_flag)
    {
        if (x > MAX_SIZE)
        {
            err_flag++;
            err_msg = "This is too big ... it won't fit ...";
            break;
        }

        read_cnt = read(fd, &buffer, 1);
            
        if (read_cnt < 0)
        {
            err_flag++;
            err_msg = "Error while reading tiles";
            break;
        }

        if (!buffer || !read_cnt)
            break;

        if (buffer == '\n')
        {
            if (!y)
            {
                width = x;
                for (int i = 0; i < width; i++)
                    if (tiles[0][i].type != '1')
                    {
                        err_flag++;
                        err_msg = "Map must be enclosed in walls"; 
                        break;
                    }
            }
            else
                if (x != width)
                {
                    err_flag++;
                    err_msg = "Map must be rectangular";
                    break;
                }

            if (tiles[y][0].type != '1' || tiles[y][width - 1].type != '1')
            {
                err_flag++;
                err_msg = "Map must be enclosed in walls"; 
                break;
            }

            y++;
            x = 0;
            continue;
        }

        if (!type_valid(buffer))
        {
            err_flag++;
            err_msg = "Map can only be made of 0 1 C P E"; 
            break;
        }

        if (buffer == 'P')
        {
            player_flag++;
            player_pos = &tiles[y][x];
        }

        if (buffer == 'E')
            stairs_flag++;

        if (buffer == 'C')
            coin_flag++;
        
        tiles[y][x].type = buffer;
        tiles[y][x].x    = x;
        tiles[y][x].y    = y;
        tiles[y][x].dirty = 1;
        x++;
    }

    if (!err_flag)
    {
        for (int i = 0; i < width; i++)
            if (tiles[y - 1][i].type != '1')
            {
                err_flag++; 
                err_msg = "Map must be enclosed in walls"; 
                break;
            }
    }

    if (!err_flag)
    {
        if (player_flag != 1 || stairs_flag != 1 || !coin_flag)
        {
            err_flag++;
            err_msg = "Map must have 1 starting position, 1 exit and at least 1 coin";
        }
    }
    
    map->tiles   = tiles;
    map->width   = width * SPRITE_RES;
    map->height  = y * SPRITE_RES;
    map->player  = player_pos;
    map->coins   = coin_flag;

    if (!err_flag)
    {
        if (!find_exit(map, player_pos->x, player_pos->y))
        {
           err_flag++;
           err_msg = "Map must have a valid path";
        }
    }

    if (err_flag)
    {
        printf("Error\n%s\n", err_msg);
        free(map);
        close(fd);
        exit(ERROR_);
    }


    close(fd);
    
    return map;
}
