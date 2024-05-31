/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:27 by tecker            #+#    #+#             */
/*   Updated: 2024/05/31 15:20:28 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	data->zoom = 50;
	data->offset_x = 0;
	data->color.start_color = 0x00E9F0;
	data->color.end_color = 0xFF45A2;
	data->map.x = 0;
	data->map.y = 0;
	data->perspective = 2;
	data->rotation = 0.523599;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->height = 2;
}
