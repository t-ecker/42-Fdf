/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:24 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 21:58:47 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	read_z_and_color(t_data *data, char *str, int j, int i)
{
	char	*c;
	int		len;
	int		start_pos;

	data->color.map_color[i][j] = 0;
	if (ft_strchr(str, ',') != NULL)
	{
		start_pos = (ft_strchr(str, ',') + 1 - str);
		len = ft_strlen(str) - start_pos;
		if (str[ft_strlen(str) - 1] == '\n')
			len--;
		c = ft_substr(str, start_pos, len);
		if (c == NULL)
			return (0);
		data->color.map_color[i][j] = ft_xtoi(c);
		if (data->color.map_color[i][j] == 0)
			return (0);
		free(c);
	}
	data->map.z[i][j] = ft_atoi(str);
	return (j + 1);
}

int	allocate_map_rows(t_data *data, char *line, int i)
{
	char	**split;
	int		j;

	j = 0;
	remove_newline(line);
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	free(line);
	data->map.x = get_size(split);
	if (check_x(data) == 1)
		return (freedoublearray(split), 1);
	data->map.z[i] = (int *)ft_calloc(data->map.x, sizeof(int));
	if (!data->map.z[i])
		return (freedoublearray(split), 1);
	data->color.map_color[i] = (int *)ft_calloc(data->map.x, sizeof(int));
	if (!data->color.map_color[i])
		return (freedoublearray(split), 1);
	while (j < data->map.x)
	{
		j = read_z_and_color(data, split[j], j, i);
		if (j == 0)
			return (freedoublearray(split), 1);
	}
	return (freedoublearray(split), 0);
}

void	read_map(t_data *data, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_exit("Error opening file\n", data);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (1 == allocate_map_rows(data, line, i))
		{
			print_error_exit("Reading map failed\n", data);
		}
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	process_map(t_data *data, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_exit("Error opening file\n", data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.z = (int **)ft_calloc(data->map.y, sizeof(int *));
	if (!data->map.z)
		print_error_exit("Error allocating memory for map.z\n", data);
	data->color.map_color = (int **)ft_calloc(data->map.y, sizeof(int *));
	if (!data->color.map_color)
		print_error_exit("Error allocating memory for color\n", data);
	read_map(data, argv);
}

void	init_data(t_data *data, char **argv)
{
	init_values(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		print_error_exit("mlx_init failed\n", data);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	if (data->mlx_win == NULL)
		print_error_exit("mlx_new_window failed\n", data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
		print_error_exit("mlx_new_image failed\n", data);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
		print_error_exit("mlx_get_data_addr failed\n", data);
	process_map(data, argv);
	find_min_max_z(data);
}
