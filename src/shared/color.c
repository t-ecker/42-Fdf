/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:10 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 21:58:41 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//extracts the colors from start/end color
//calculates the change in color change
// and multiplies it times t to the start_color
//merges each individual color bag together to a rgb color
int	calc_color(t_data *data, float t)
{
	int	r;
	int	g;
	int	b;

	data->color.r_s = (data->color.start_color >> 16) & 0xFF;
	data->color.g_s = (data->color.start_color >> 8) & 0xFF;
	data->color.b_s = data->color.start_color & 0xFF;
	data->color.r_e = (data->color.end_color >> 16) & 0xFF;
	data->color.g_e = (data->color.end_color >> 8) & 0xFF;
	data->color.b_e = data->color.end_color & 0xFF;
	r = data->color.r_s + t * (data->color.r_e - data->color.r_s);
	g = data->color.g_s + t * (data->color.g_e - data->color.g_s);
	b = data->color.b_s + t * (data->color.b_e - data->color.b_s);
	return ((r << 16) | (g << 8) | b);
}

//calc a percentage that is based on how high the z is in the range of z
// t = float between 0 and 1. 0 would be min_z 1 would be max_z
int	calc_perc_color(t_data *data, int current_z, int neighbor_z, int b)
{
	int		range;
	float	t;
	int		z;

	if (b == 1)
		z = (current_z + neighbor_z) / 2;
	else
		z = current_z;
	range = data->map.max_z - data->map.min_z;
	t = (float)(z - data->map.min_z) / range;
	return (calc_color(data, t));
}

int	get_color(t_data *data, int x, int y, int b)
{
	int	current_z;
	int	current_col;
	int	neighbor_z;
	int	neighbor_col;

	current_z = data->map.z[y][x];
	current_col = data->color.map_color[y][x];
	if (b == 1)
	{
		neighbor_z = data->map.z[y][x + 1];
		neighbor_col = data->color.map_color[y][x + 1];
	}
	else
	{
		neighbor_z = data->map.z[y + 1][x];
		neighbor_col = data->color.map_color[y + 1][x];
	}
	if (data->map.max_z == data->map.min_z)
		return (data->color.start_color);
	if (current_z != neighbor_z && (current_col == 0))
		return (calc_perc_color(data, current_z, neighbor_z, 1));
	else if (current_col != 0 && neighbor_col != 0)
		return (current_col);
	else
		return (calc_perc_color(data, current_z, neighbor_z, 0));
}
