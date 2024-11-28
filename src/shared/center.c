/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:03 by tecker            #+#    #+#             */
/*   Updated: 2024/11/29 00:13:32 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	all_points_visible(t_data *data)
{
	center(data);
	return (data->borders.max_x + data->base_offset_x < WIDTH - 50
		&& data->borders.min_x + data->base_offset_x > 0 + 50
		&& data->borders.max_y + data->base_offset_y < HEIGHT - 50
		&& data->borders.min_y + data->base_offset_y > 0 + 50);
}

void	center(t_data *data)
{
	data->borders.max_x = INT_MIN;
	data->borders.max_y = INT_MIN;
	data->borders.min_x = INT_MAX;
	data->borders.min_y = INT_MAX;
	get_borders(data, -1, -1);
	set_offset(data);
}

//calculates the min/max x/y values after isometric calculation
void	get_borders(t_data *data, int y, int x)
{
	t_two_points p;

	p.x1 = 0;
	p.y1 = 0;
	while (++y < data->map.y)
	{
		x = -1;
		while (++x < data->map.x)
		{
			p.x0 = x * data->zoom;
			p.y0 = y * data->zoom;
			rotate(data, &p);
			isometric(data, &p, data->map.points[y][x], data->map.points[y][x]);
			if (p.x0 < data->borders.min_x)
				data->borders.min_x = p.x0;
			if (p.x0 > data->borders.max_x)
				data->borders.max_x = p.x0;
			if (p.y0 < data->borders.min_y)
				data->borders.min_y = p.y0;
			if (p.y0 > data->borders.max_y)
				data->borders.max_y = p.y0;
		}
	}
}

//calculates the offsets by doing: middle screen - middle object
void	set_offset(t_data *data)
{
	int	screen_center_x;
	int	screen_center_y;
	int	object_center_x;
	int	object_center_y;

	screen_center_x = WIDTH / 2;
	screen_center_y = HEIGHT / 2;
	if (data->perspective == 1)
	{
		object_center_x = (data->map.x / 2) * data->zoom;
		object_center_y = (data->map.y / 2) * data->zoom;
	}
	else
	{
		object_center_x = data->borders.min_x
			+ (data->borders.max_x - data->borders.min_x) / 2;
		object_center_y = data->borders.min_y
			+ (data->borders.max_y - data->borders.min_y) / 2;
	}
	data->base_offset_x = screen_center_x - object_center_x;
	data->base_offset_y = screen_center_y - object_center_y;
}
