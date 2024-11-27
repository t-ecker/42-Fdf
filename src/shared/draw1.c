/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:14 by tecker            #+#    #+#             */
/*   Updated: 2024/11/27 20:57:24 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// void	draw_line(t_data *data, t_two_points p, int color)
// {
// 	t_line	line;
// 	int		i;

// 	i = 0;
// 	line.dy = p.y1 - p.y0;
// 	line.dx = p.x1 - p.x0;
// 	if (ft_abs(line.dx) > ft_abs(line.dy))
// 		line.steps = ft_abs(line.dx);
// 	else
// 		line.steps = ft_abs(line.dy);
// 	line.x_inc = (float)line.dx / line.steps;
// 	line.y_inc = (float)line.dy / line.steps;
// 	line.x = (float)p.x0;
// 	line.y = (float)p.y0;
// 	while (i <= line.steps)
// 	{
// 		my_put_pixel(data->mlx.main, (int)round(line.x), (int)round(line.y), color);
// 		line.x += line.x_inc;
// 		line.y += line.y_inc;
// 		i++;
// 	}
// }

void	draw_line(t_data *data, t_two_points p, t_points start, t_points end)
{
	t_line	line;
	int		i;

	i = -1;
	line.dy = p.y1 - p.y0;
	line.dx = p.x1 - p.x0;
	if (ft_abs(line.dx) > ft_abs(line.dy))
		line.steps = ft_abs(line.dx);
	else
		line.steps = ft_abs(line.dy);
	line.x_inc = (float)line.dx / line.steps;
	line.y_inc = (float)line.dy / line.steps;
	line.x = (float)p.x0;
	line.y = (float)p.y0;
	line.z_inc = (float)(end.z - start.z) / line.steps;
	line.z = start.z;
	while (++i <= line.steps)
	{
		line.t = (line.z - data->map.min_z) / (data->map.max_z - data->map.min_z);
		my_put_pixel(data->mlx.main, (int)round(line.x), (int)round(line.y), get_color(data, start, end, line.t));
		line.x += line.x_inc;
		line.y += line.y_inc;
		line.z += line.z_inc;
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
		*y = (prev_x + prev_y) * sin(data->rotation) - (z * data->zoom * data->height);
	}
}

void	draw_map_operations(int x, int y, t_data *data)
{
	t_two_points p;
	
	p.x0 = x * data->zoom;
	p.y0 = y * data->zoom;
	isometric(&p.x0, &p.y0, data->map.points[y][x].z, data);
	add_offset(&p.x0, &p.y0, data);
	if (x < data->map.x - 1)
	{
		p.x1 = (x + 1) * data->zoom;
		p.y1 = y * data->zoom;
		isometric(&p.x1, &p.y1,
			data->map.points[y][x + 1].z, data);
		add_offset(&p.x1, &p.y1, data);
		draw_line(data, p, data->map.points[y][x], data->map.points[y][x + 1]);
	}
	if (y < data->map.y - 1)
	{
		p.x1 = x * data->zoom;
		p.y1 = (y + 1) * data->zoom;
		isometric(&p.x1, &p.y1,
			data->map.points[y + 1][x].z, data);
		add_offset(&p.x1, &p.y1, data);
		draw_line(data, p, data->map.points[y][x], data->map.points[y + 1][x]);
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
