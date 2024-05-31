/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:19:45 by tecker            #+#    #+#             */
/*   Updated: 2024/05/31 22:31:29 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Wrong arguments");
		exit(1);
	}
	else if (ft_is_format(argv[1], ".fdf") == 0)
	{
		perror("Wrong format");
		exit(1);
	}
	else if (ft_is_readable(argv[1]) == 0)
	{
		perror("Read Error");
		exit(1);
	}
}

int	key_press(int key, t_data *data)
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
