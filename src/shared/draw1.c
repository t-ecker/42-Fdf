/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:14 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 01:40:33 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	draw_line(t_data *data, int color)
{
	t_line	line;
	int		i;

	i = 0;
	line.dy = data->p.y1 - data->p.y0;
	line.dx = data->p.x1 - data->p.x0;
	if (ft_abs(line.dx) > ft_abs(line.dy))
		line.steps = ft_abs(line.dx);
	else
		line.steps = ft_abs(line.dy);
	line.x_inc = (float)line.dx / line.steps;
	line.y_inc = (float)line.dy / line.steps;
	line.x = (float)data->p.x0;
	line.y = (float)data->p.y0;
	while (i <= line.steps)
	{
		my_put_pixel(data->mlx.main, (int)round(line.x), (int)round(line.y), color);
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
		return ;
	else
	{
		prev_x = *x;
		prev_y = *y;
		*x = (prev_x - prev_y) * cos(data->rotation);
		*y = (prev_x + prev_y) * sin(data->rotation) - (data->height * z);
	}
}

void	draw_map_operations(int x, int y, t_data *data)
{
	data->p.x0 = x * data->zoom;
	data->p.y0 = y * data->zoom;
	isometric(&data->p.x0, &data->p.y0, data->map.points[y][x].z, data);
	add_offset(&data->p.x0, &data->p.y0, data);
	if (x < data->map.x - 1)
	{
		data->p.x1 = (x + 1) * data->zoom;
		data->p.y1 = y * data->zoom;
		isometric(&data->p.x1, &data->p.y1,
			data->map.points[y][x + 1].z, data);
		add_offset(&data->p.x1, &data->p.y1, data);
		draw_line(data, get_color(data, x, y, 1));
	}
	if (y < data->map.y - 1)
	{
		data->p.x1 = x * data->zoom;
		data->p.y1 = (y + 1) * data->zoom;
		isometric(&data->p.x1, &data->p.y1,
			data->map.points[y + 1][x].z, data);
		add_offset(&data->p.x1, &data->p.y1, data);
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
