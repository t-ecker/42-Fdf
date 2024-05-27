#include "../fdf.h"

void	draw(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	print_background(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
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
			my_mlx_pixel_put(data, j, i, 0x424242);
			j++;
		}
		i++;
	}
}
