/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:19:54 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 21:59:00 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	change_color(t_data *data)
{
	if (data->color.start_color == 0x00E9F0)
	{
		data->color.start_color = 0xFF45A2;
		data->color.end_color = 0xF5E717;
	}
	else
	{
		data->color.start_color = 0x00E9F0;
		data->color.end_color = 0xFF45A2;
	}
}

void	change_perspective(t_data *data)
{
	if (data->perspective == 1)
		data->perspective++;
	else
		data->perspective--;
	draw_start(data);
}

void	change_z(t_data *data)
{
	if (data->height == 2)
		data->height = data->zoom;
	else
		data->height = 2;
	draw_start(data);
}

int	key_press(int key, t_data *data)
{
	if (key == 53)
		handle_close(data);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		if (key == 123)
			data->offset_x += 50;
		else if (key == 124)
			data->offset_x -= 50;
		else if (key == 125)
			data->offset_y -= 50;
		else if (key == 126)
			data->offset_y += 50;
	}
	else if (key == 24 && data->zoom < 200)
		data->zoom += 1;
	else if (key == 27 && data->zoom > 1)
		data->zoom -= 1;
	else if (key == 8)
		change_color(data);
	else if (key == 35)
		change_perspective(data);
	else if (key == 6)
		return (change_z(data), 0);
	return (draw(data), 0);
}

int	handle_mouse_scroll(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4 && data->zoom > 1)
		data->zoom -= 1;
	else if (button == 5 && data->zoom < 200)
		data->zoom += 1;
	draw(data);
	return (0);
}
