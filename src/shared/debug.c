#include "../../fdf.h"

void print_debug_map(t_data *data)
{
    printf("Map Debug Information:\n");
    printf("Map Dimensions: %d x %d\n\n", data->map.y, data->map.x);

    for (int y = 0; y < data->map.y; y++)
    {
        for (int x = 0; x < data->map.x; x++)
        {
            if (data->map.points[y][x].color != 0)
                printf("\033[31m%2d\033[0m ", data->map.points[y][x].z); // Red for non-zero color
            else
                printf("\033[37m%2d\033[0m ", data->map.points[y][x].z); // White for zero color
        }
        printf("\n");
    }
}