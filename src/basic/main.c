/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:19:45 by tecker            #+#    #+#             */
/*   Updated: 2024/11/26 01:32:57 by tomecker         ###   ########.fr       */
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
		ft_putstr_fd("Wrong arguments\n", 2);
		exit(1);
	}
	else if (ft_is_readable(argv[1]) == 0)
	{
		ft_putstr_fd("Wrong arguments\n", 2);
		exit(1);
	}
}

void	key_press(int key, t_data *data)
{
	if (key == 53)
		handle_close(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argv);
	draw_start(&data);
	mlx_hook(data.mlx_win, 2, 0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
