/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:19:59 by tecker            #+#    #+#             */
/*   Updated: 2024/11/30 01:27:57 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Wrong arguments\n", 2);
		exit(1);
	}
	else if (ft_is_format(argv[1], ".fdf") == 0)
	{
		ft_putstr_fd("Wrong format\n", 2);
		exit(1);
	}
	else if (ft_is_readable(argv[1]) == 0)
	{
		ft_putstr_fd("Read Error\n", 2);
		exit(1);
	}
}

void	ft_hook(t_data *data)
{
	mlx_loop_hook(data->mlx.mlx, key_press_multi, data);
	mlx_key_hook(data->mlx.mlx, key_press_single, data);
	mlx_scroll_hook(data->mlx.mlx, handle_mouse_scroll, data);
	mlx_cursor_hook(data->mlx.mlx, cursor_hook, data);
    mlx_mouse_hook(data->mlx.mlx, mouse_hook, data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argv);
	print_debug_map(&data);
	draw_img(data.mlx.overlay, data.mlx.active, 0, 0);
	ft_hook(&data);
	mlx_loop_hook(data.mlx.mlx, draw, &data);
	mlx_loop(data.mlx.mlx);
	freedoublearray_point(data.map.points, data.map.y);
	return (0);
}
