/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:10 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 02:08:01 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//extracts the colors from start/end color
//calculates the change in color change
// and multiplies it times t to the start_color
//merges each individual color bag together to a rgb color
int	calc_color(t_data *data, float t)
{
	int	r, g, b, a;

	// Extract RGBA components for the start color
	data->color.r_s = (data->color.start_color >> 24) & 0xFF;
	data->color.g_s = (data->color.start_color >> 16) & 0xFF;
	data->color.b_s = (data->color.start_color >> 8) & 0xFF;
	data->color.a_s = data->color.start_color & 0xFF;

	// Extract RGBA components for the end color
	data->color.r_e = (data->color.end_color >> 24) & 0xFF;
	data->color.g_e = (data->color.end_color >> 16) & 0xFF;
	data->color.b_e = (data->color.end_color >> 8) & 0xFF;
	data->color.a_e = data->color.end_color & 0xFF;

	// Interpolate each component
	r = data->color.r_s + t * (data->color.r_e - data->color.r_s);
	g = data->color.g_s + t * (data->color.g_e - data->color.g_s);
	b = data->color.b_s + t * (data->color.b_e - data->color.b_s);
	a = data->color.a_s + t * (data->color.a_e - data->color.a_s);

	// Combine components into a single RGBA value
	return ((r << 24) | (g << 16) | (b << 8) | a);
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

	current_z = data->map.points[y][x].z;
	current_col = data->map.points[y][x].color;
	if (b == 1)
	{
		neighbor_z = data->map.points[y][x + 1].z;
		neighbor_col = data->map.points[y][x + 1].color;
	}
	else
	{
		neighbor_z = data->map.points[y + 1][x].z;
		neighbor_col = data->map.points[y + 1][x].color;
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
