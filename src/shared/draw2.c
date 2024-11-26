/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:19 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 02:31:23 by tomecker         ###   ########.fr       */
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
	while (!all_points_visible(data) && data->zoom > 1)
		data->zoom--;
	print_background(data);
	draw_map(data);
}

void	draw(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	write(1, "yy\n", 3);
	clear_image(data->mlx.bg);
	clear_image(data->mlx.main);
	print_background(data);
	draw_map(data);
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
			my_put_pixel(data->mlx.bg, j, i, 0x424242FF);
			j++;
		}
		i++;
	}
}

void	my_put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
		mlx_put_pixel(img, x, y, color);
}
