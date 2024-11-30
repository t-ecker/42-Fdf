/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:19 by tecker            #+#    #+#             */
/*   Updated: 2024/11/30 01:34:44 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	clear_image(mlx_image_t *image)
{
	uint32_t	transparent_color;
	uint32_t	y;
	uint32_t	x;

	y = 0;
	transparent_color = 0x00000000;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, transparent_color);
			x++;
		}
		y++;
	}
}

void	draw_start(t_data *data)
{
	data->start = 0;
	reset(data);
	clear_image(data->mlx.overlay);
	draw_overlay(data);
}

void	draw(void *param)
{
	t_data	*data;
	static int old_hover = 0;
	static int old_click = 4;

	data = (t_data *)param;
	if (data->is_hovered != old_hover || data->is_clicked != old_click)
	{
		// printf("%i\n", data->is_hovered);
		if (data->is_clicked == old_click)
			clear_image(data->mlx.hover_overlay);
		old_click = data->is_clicked;
		old_hover = data->is_hovered;
		if (data->mlx.active)
			draw_img(data->mlx.overlay, data->mlx.active, 0, 0);
	}
	if (!data->start)
	{
		print_background(data);
		draw_map(data);
	}	
}

void	print_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_put_pixel(data->mlx.main, j, i, data->background_color);
			j++;
		}
		i++;
	}
}

int is_outside(int x, int y)
{
	return (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0);
}

void	my_put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (is_outside(x, y))
		mlx_put_pixel(img, x, y, color);
}
