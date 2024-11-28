/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:10 by tecker            #+#    #+#             */
/*   Updated: 2024/11/27 21:08:37 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//extracts the colors from start/end color
//calculates the change in color change
// and multiplies it times t to the start_color
//merges each individual color bag together to a rgb color
int	calc_color(float t, int start_color, int end_color)
{
	int	r;
	int	g;
	int	b;
	int	a;
	t_color color;

	color.r_s = (start_color >> 24) & 0xFF;
	color.g_s = (start_color >> 16) & 0xFF;
	color.b_s = (start_color >> 8) & 0xFF;
	color.a_s = start_color & 0xFF;
	color.r_e = (end_color >> 24) & 0xFF;
	color.g_e = (end_color >> 16) & 0xFF;
	color.b_e = (end_color >> 8) & 0xFF;
	color.a_e = end_color & 0xFF;
	r = color.r_s + t * (color.r_e - color.r_s);
	g = color.g_s + t * (color.g_e - color.g_s);
	b = color.b_s + t * (color.b_e - color.b_s);
	a = color.a_s + t * (color.a_e - color.a_s);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	get_color(t_data *data, t_points start, t_points end, float t)
{
	if (data->map.max_z == data->map.min_z)
		return (data->start_color);
	else if (start.color != 0 && end.color == start.color)
		return (start.color);
	if (start.color != 0 && end.color == 0)
		return (calc_color(1 - t, start.color, data->start_color));
	if (start.color == 0 && end.color != 0)
		return (calc_color(t, data->start_color, end.color));
	if (start.color != 0 && end.color != 0)
		return (calc_color(t, start.color, end.color));
	else
		return (calc_color(t, data->start_color, data->end_color));
}
