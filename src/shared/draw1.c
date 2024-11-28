/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:14 by tecker            #+#    #+#             */
/*   Updated: 2024/11/29 00:24:17 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void init_line(t_line *line, t_two_points p)
{
	line->dy = p.y1 - p.y0;
	line->dx = p.x1 - p.x0;
	if (ft_abs(line->dx) > ft_abs(line->dy))
		line->steps = ft_abs(line->dx);
	else
		line->steps = ft_abs(line->dy);
	line->x_inc = (float)line->dx / line->steps;
	line->y_inc = (float)line->dy / line->steps;
	line->x = (float)p.x0;
	line->y = (float)p.y0;
}

void	draw_line(t_data *data, t_two_points p, t_points start, t_points end)
{
	t_line	line;
	int		i;

	i = -1;
	init_line(&line, p);
	line.z_inc = (float)(end.z - start.z) / line.steps;
	line.z = start.z;
	while (++i <= line.steps)
	{
		line.t = (line.z - data->map.min_z) / (data->map.max_z - data->map.min_z);
		if (is_outside((int)round(line.x), (int)round(line.y)))
			my_put_pixel(data->mlx.main, (int)round(line.x),
				(int)round(line.y), get_color(data, start, end, line.t));
		line.x += line.x_inc;
		line.y += line.y_inc;
		line.z += line.z_inc;
	}
}

void rotate(t_data *data, t_two_points *p)
{
	int prev_x;
    int prev_y;
    float cos_rot;
    float sin_rot;
	
	sin_rot = sin(data->rotation_angle);
	cos_rot = cos(data->rotation_angle);
	prev_x = p->x0 - (data->map.x * data->zoom / 2);
	prev_y = p->y0 - (data->map.y * data->zoom / 2);
	p->x0 = (prev_x * cos_rot - prev_y * sin_rot);
	p->y0 = (prev_x * sin_rot + prev_y * cos_rot);
	prev_x = p->x1 - (data->map.x * data->zoom / 2);
	prev_y = p->y1 - (data->map.y * data->zoom / 2);
	p->x1 = (prev_x * cos_rot - prev_y * sin_rot);
	p->y1 = (prev_x * sin_rot + prev_y * cos_rot);
}

void isometric(t_data *data, t_two_points *p, t_points start, t_points end)
{
	int	prev_x;
	int	prev_y;

	if (data->perspective == 1)
		return ;
	else
	{
		prev_x = p->x0;
		prev_y = p->y0;
		p->x0 = (prev_x - prev_y) * cos(0.523599);
		p->y0 = (prev_x + prev_y) * sin(0.523599) - (start.z * data->zoom * data->height);
		prev_x = p->x1;
		prev_y = p->y1;
		p->x1 = (prev_x - prev_y) * cos(0.523599);
		p->y1 = (prev_x + prev_y) * sin(0.523599) - (end.z * data->zoom * data->height);
    }
}

void scale(t_data *data, t_two_points *p, t_points start, t_points end)
{
	p->x0 = start.x * data->zoom;
	p->y0 = start.y * data->zoom;
	p->x1 = end.x * data->zoom;
	p->y1 = end.y * data->zoom;
}

void	add_offset(t_data *data, t_two_points *p)
{
	p->x0 += data->base_offset_x + data->offset_x;
	p->y0 += data->base_offset_y + data->offset_y;
	p->x1 += data->base_offset_x + data->offset_x;
	p->y1 += data->base_offset_y + data->offset_y;
}

void	draw_map_operations(t_data *data, t_points start, t_points end)
{
	t_two_points p;
	
	scale(data, &p, start, end);
	rotate(data, &p);
	isometric(data, &p, start, end);
	add_offset(data, &p);
	draw_line(data, p, start, end);
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
			if (x < data->map.x - 1)
				draw_map_operations(data, data->map.points[y][x], data->map.points[y][x + 1]);
			if (y < data->map.y - 1)
				draw_map_operations(data, data->map.points[y][x], data->map.points[y + 1][x]);
			x++;
		}
		y++;
	}
}
