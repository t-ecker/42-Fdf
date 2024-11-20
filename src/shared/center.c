/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:03 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 21:58:32 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	all_points_visible(t_data *data)
{
	data->borders.max_x = INT_MIN;
	data->borders.max_y = INT_MIN;
	data->borders.min_x = INT_MAX;
	data->borders.min_y = INT_MAX;
	get_borders(data);
	set_offset(data);
	return (data->borders.max_x + data->offset_x < WIDTH - 50
		&& data->borders.min_x + data->offset_x > 0 + 50
		&& data->borders.max_y + data->offset_y < HEIGHT - 50
		&& data->borders.min_y + data->offset_y > 0 + 50);
}

//calculates the min/max x/y values after isometric calculation
void	get_borders(t_data *data)
{
	int	x;
	int	y;
	int	iso_x;
	int	iso_y;

	y = -1;
	while (++y < data->map.y)
	{
		x = -1;
		while (++x < data->map.x)
		{
			iso_x = x * data->zoom;
			iso_y = y * data->zoom;
			isometric(&iso_x, &iso_y, data->map.z[y][x], data);
			if (iso_x < data->borders.min_x)
				data->borders.min_x = iso_x;
			if (iso_x > data->borders.max_x)
				data->borders.max_x = iso_x;
			if (iso_y < data->borders.min_y)
				data->borders.min_y = iso_y;
			if (iso_y > data->borders.max_y)
				data->borders.max_y = iso_y;
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
	data->offset_x = screen_center_x - object_center_x;
	data->offset_y = screen_center_y - object_center_y;
}

void	add_offset(int *x, int *y, t_data *data)
{
	*x += data->offset_x;
	*y += data->offset_y;
}
