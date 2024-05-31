/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:31 by tecker            #+#    #+#             */
/*   Updated: 2024/05/31 17:04:21 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_xtoi(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		num *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			num += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			num += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			num += str[i] - 'a' + 10;
		else
		{
			write(1, "Invalid hexadecimal character\n", 30);
			return (0);
		}
		i++;
	}
	return (num);
}

void	freedoublearray(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	freedoublearray_int(int **array, t_data *data)
{
	int	i;

	if (array)
	{
		i = 0;
		while (i < data->map.y)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
		free(array);
	}
}

int	handle_close(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	freedoublearray_int(data->map.z, data);
	freedoublearray_int(data->color.map_color, data);
	exit(0);
}

void	print_error_exit(char *str, t_data *data)
{
	perror(str);
	handle_close(data);
}
