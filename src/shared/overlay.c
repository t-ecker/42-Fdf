/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:41:40 by tomecker          #+#    #+#             */
/*   Updated: 2024/11/29 21:02:11 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int darken_color(int color, float percentage)
{
	t_color c;

    c.r_s = (color >> 24) & 0xFF;
    c.g_s = (color >> 16) & 0xFF;
    c.b_s = (color >> 8) & 0xFF;

    if (percentage < 0.0f)
		percentage = 0.0f;
    if (percentage > 1.0f)
		percentage = 1.0f;

    c.r_e = (c.r_s * (1 - percentage));
    c.g_e = (c.g_s * (1 - percentage));
    c.b_e = (c.b_s * (1 - percentage));

    return (c.r_e << 24) | (c.g_e << 16) | (c.b_e << 8) | 0x90;
}

int	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	int		index;
	t_color	color;

	if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (0);
	index = (y * texture->width + x) * 4;
	color.r_s = texture->pixels[index];
	color.g_s = texture->pixels[index + 1];
	color.b_s = texture->pixels[index + 2];
	color.a_s = texture->pixels[index + 3];

	if (color.a_s == 0x0)
		return (0);
	return (color.r_s << 24) | (color.g_s << 16) | (color.b_s << 8) | color.a_s;
}

void	draw_img(mlx_image_t *img, mlx_texture_t *texture,
		int dst_x, int dst_y)
{
	int	y;
	int	x;
	int color;

	y = 0;
	while (y < (int)texture->height)
	{
		x = 0;
		while (x < (int)texture->width)
		{
			color = get_texture_color(texture, x, y);
			if (color != 0)
				my_put_pixel(img, dst_x + x, dst_y + y,
					color);
			x++;
		}
		y++;
	}
}

void draw_overlay(t_data *data)
{
    int overlay_width;
	int	y;
	int	x;

	overlay_width = 400;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < overlay_width)
		{
			mlx_put_pixel(data->mlx.overlay, x, y, darken_color(data->background_color, 0.2));
			x++;
		}
		y++;
	}
	draw_img(data->mlx.overlay, data->mlx.active, 0, 0);
}