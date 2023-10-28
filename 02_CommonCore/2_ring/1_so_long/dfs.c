#include "so_long.h"

int find_exit(t_map *map, int x, int y)
{
    t_tile tile;

    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
            return 0;

    tile = map->tiles[y][x];

    if (tile.type == 'E')
        return 1;

    if (tile.type == 'W' || tile.visited)
        return 0;

    map->tiles[y][x].visited = 1;

    if (find_exit(map, x, y - 1) || find_exit(map, x, y + 1) ||
            find_exit(map, x - 1, y) ||find_exit(map, x + 1, y))
        return 1;

    return 0;
}
