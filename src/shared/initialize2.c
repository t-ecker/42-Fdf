/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:27 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 23:24:59 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	find_min_max_z(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->map.min_z = INT_MAX;
	data->map.max_z = INT_MIN;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.points[y][x].z < data->map.min_z)
				data->map.min_z = data->map.points[y][x].z;
			if (data->map.points[y][x].z > data->map.max_z)
				data->map.max_z = data->map.points[y][x].z;
			x++;
		}
		y++;
	}
}

void	init_values(t_data *data)
{
	data->zoom = 50;
	data->offset_x = 0;
	data->start_color = 0x00E9F0FF;
	data->end_color = 0xFF45A2FF;
	data->map.x = 0;
	data->map.y = 0;
	data->map.points = NULL;
	data->perspective = 2;
	data->rotation = 0.523599;
	data->height = 1.0;
}
