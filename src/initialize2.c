#include "../fdf.h"

void	find_min_max_z(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->map.min_z = data->map.z[0][0];
	data->map.max_z = data->map.z[0][0];
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.z[y][x] < data->map.min_z)
				data->map.min_z = data->map.z[y][x];
			if (data->map.z[y][x] > data->map.max_z)
				data->map.max_z = data->map.z[y][x];
			x++;
		}
		y++;
	}
}

void	init_values(t_data *data)
{
	data->zoom = 6;
	data->color.start_color = 0x00E9F0;
	data->color.end_color = 0xFF45A2;
	data->map.x = 0;
	data->map.y = 0;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
}

void	set_offset(t_data *data)
{
	int	content_width;
	int	content_height;
	int	screen_center_x;
	int	screen_center_y;

	content_height = data->map.y * data->zoom;
	content_width = data->map.x * data->zoom;
	screen_center_x = WIDTH / 2;
	screen_center_y = HEIGHT / 2;
	data->offset_x = screen_center_x - content_width / 2;
	data->offset_y = screen_center_y - content_height / 2;
}
