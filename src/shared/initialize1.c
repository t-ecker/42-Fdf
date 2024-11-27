/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:24 by tecker            #+#    #+#             */
/*   Updated: 2024/11/27 20:53:47 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	get_z_and_color(t_data *data, char *line, int y, int x)
{
	char	**split;
	char *comma_pos;
	
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	while (split[x])
	{
		data->map.points[y][x].x = x;
		data->map.points[y][x].y = y;
		data->map.points[y][x].z = ft_atoi(split[x]);
		comma_pos = ft_strchr(split[x], ',');
		if (comma_pos != NULL)
		{
			data->map.points[y][x].color = ft_xtoi(join_color(++comma_pos));
			if (data->map.points[y][x].color == 0)
				return (freedoublearray(split), 1);
		}
		else
			data->map.points[y][x].color = 0;
		x++;
	}
	if (x != data->map.x)
		return (freedoublearray(split), 1);
	return (freedoublearray(split), 0);
}

void	read_map(t_data *data, char **argv)
{
	int		fd;
	int		y;
	int		x;
	char	*line;

	y = 0;
	x = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_exit("Error opening file\n", data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (get_z_and_color(data, line, y++, x))
		{
			free(line);
			print_error_exit("reading map faild\n", data);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (y != data->map.y)
		print_error_exit("reading map failed\n", data);
	close(fd);
}

void	check_map(t_data *data, char *str)
{
	static int max = -1;
	int count = 1;
	int i = 0;
	if (str[0] == '\n')
		print_error_exit("wrong map (multiple empty lines found)\n", data);
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] == ' ' && str[i + 1] == '\n')
			print_error_exit("wrong map (space at the end of a line)\n", data);
		if (str[i] == ' ')
		{
			if (i != 0 && ft_isalnum(str[i - 1]))
				count++;
			while (str[i] && str[i] == ' ')
				i++;
		}
	}
	if (max != -1 && max != count)
		print_error_exit("wrong map (different line lengths)\n", data);
	data->map.y++;
	data->map.x = count;
	max = count;
	free(str);
}

void	process_map(t_data *data, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_exit("Error opening file\n", data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_map(data, line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.points = (t_points **)ft_calloc(data->map.y, sizeof(t_points *));
	if (!data->map.points)
		print_error_exit("Error allocating memory for map.points\n", data);
	while (i < data->map.y)
	{
		data->map.points[i] = (t_points *)ft_calloc(data->map.x, sizeof(t_points));
		if (!data->map.points[i++])
			print_error_exit("Error allocating memory for map.points\n", data);
	}
	read_map(data, argv);
}

void	init_data(t_data *data, char **argv)
{
	char *title;

	init_values(data);
	process_map(data, argv);
	find_min_max_z(data);
	title = ft_strjoin("fdf - map: ", ft_strrchr(argv[1], '/') + 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx.mlx = mlx_init(WIDTH, HEIGHT, title, 1);
	if (!data->mlx.mlx)
		print_error_exit("mlx init failed\n", data);
	data->mlx.main = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (!data->mlx.main
		|| (mlx_image_to_window(data->mlx.mlx, data->mlx.main, 0, 0) < 0))
		handle_close(data);
}
