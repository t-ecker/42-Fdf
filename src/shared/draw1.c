#include "../fdf.h"

void	draw_line(t_data *data, int color)
{
	t_line	line;
	int		i;

	i = 0;
	line.dy = data->point.y1 - data->point.y0;
	line.dx = data->point.x1 - data->point.x0;
	if (ft_abs(line.dx) > ft_abs(line.dy))
		line.steps = ft_abs(line.dx);
	else
		line.steps = ft_abs(line.dy);
	line.x_inc = (float)line.dx / line.steps;
	line.y_inc = (float)line.dy / line.steps;
	line.x = (float)data->point.x0;
	line.y = (float)data->point.y0;
	while (i <= line.steps)
	{
		my_mlx_pixel_put(data, (int)round(line.x), (int)round(line.y), color);
		line.x += line.x_inc;
		line.y += line.y_inc;
		i++;
	}
}

void	isometric(int *x, int *y, int z, t_data *data)
{
	int	prev_x;
	int	prev_y;

	if (data->perspective == 1)
	{
		*x += data->offset_x;
		*y += data->offset_y;
	}
	else
	{
		prev_x = *x;
		prev_y = *y;
		*x = (prev_x - prev_y) * cos(data->rotation) + data->offset_x;
		*y = (prev_x + prev_y) * sin(data->rotation) - (2 * z) + data->offset_y;
	}
}

void	draw_map_operations(int x, int y, t_data *data)
{
	data->point.x0 = x * data->zoom;
	data->point.y0 = y * data->zoom;
	isometric(&data->point.x0, &data->point.y0, data->map.z[y][x], data);
	if (x < data->map.x - 1)
	{
		data->point.x1 = (x + 1) * data->zoom;
		data->point.y1 = y * data->zoom;
		isometric(&data->point.x1, &data->point.y1,
			data->map.z[y][x + 1], data);
		draw_line(data, get_color(data, x, y, 1));
	}
	if (y < data->map.y - 1)
	{
		data->point.x1 = x * data->zoom;
		data->point.y1 = (y + 1) * data->zoom;
		isometric(&data->point.x1, &data->point.y1,
			data->map.z[y + 1][x], data);
		draw_line(data, get_color(data, x, y, 0));
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			draw_map_operations(x, y, data);
			x++;
		}
		y++;
	}
}
