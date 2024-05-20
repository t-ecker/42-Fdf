#include "./mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_data {
    void    *mlx;
    void    *mlx_win;
    int     is_dragging;
    int     last_x;
    int     last_y;
} t_data;

int handle_mouse_press(int button, int x, int y, t_data *data)
{
    if (button == 1) // Left mouse button
    {
        data->is_dragging = 1;
        data->last_x = x;
        data->last_y = y;
    }
    return 0;
}

int handle_mouse_release(int button, int x, int y, t_data *data)
{
    if (button == 1) // Left mouse button
    {
        data->is_dragging = 0;
    }
    return 0;
}

int handle_mouse_move(int x, int y, t_data *data)
{
    if (data->is_dragging)
    {
        int delta_x = x - data->last_x;
        int delta_y = y - data->last_y;

        // Determine the drag direction
        if (delta_x > 0 && abs(delta_x) > abs(delta_y))
            printf("Dragging Right\n");
        else if (delta_x < 0 && abs(delta_x) > abs(delta_y))
            printf("Dragging Left\n");
        else if (delta_y > 0 && abs(delta_y) > abs(delta_x))
            printf("Dragging Down\n");
        else if (delta_y < 0 && abs(delta_y) > abs(delta_x))
            printf("Dragging Up\n");

        // Update last known mouse position
        data->last_x = x;
        data->last_y = y;

        // Perform your dragging actions here
    }
    return 0;
}

int main()
{
    t_data data;

    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 800, 600, "Mouse Drag Test");
    data.is_dragging = 0;

    mlx_hook(data.mlx_win, 4, 0, handle_mouse_press, &data); // Mouse button press
    mlx_hook(data.mlx_win, 5, 0, handle_mouse_release, &data); // Mouse button release
    mlx_hook(data.mlx_win, 6, 0, handle_mouse_move, &data); // Mouse motion

    mlx_loop(data.mlx);
    
    return 0;
}
