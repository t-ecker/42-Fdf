/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:10 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 21:38:11 by tomecker         ###   ########.fr       */
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
	int	a;
	t_color color;

	color.r_s = (data->start_color >> 24) & 0xFF;
	color.g_s = (data->start_color >> 16) & 0xFF;
	color.b_s = (data->start_color >> 8) & 0xFF;
	color.a_s = data->start_color & 0xFF;
	color.r_e = (data->end_color >> 24) & 0xFF;
	color.g_e = (data->end_color >> 16) & 0xFF;
	color.b_e = (data->end_color >> 8) & 0xFF;
	color.a_e = data->end_color & 0xFF;
	r = color.r_s + t * (color.r_e - color.r_s);
	g = color.g_s + t * (color.g_e - color.g_s);
	b = color.b_s + t * (color.b_e - color.b_s);
	a = color.a_s + t * (color.a_e - color.a_s);
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
		return (data->start_color);
	else if (current_col != 0 && neighbor_col != 0)
		return (current_col);
	if (current_z != neighbor_z)
		return (calc_perc_color(data, current_z, neighbor_z, 1));
	else
		return (calc_perc_color(data, current_z, neighbor_z, 0));
}
