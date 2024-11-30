/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:31 by tecker            #+#    #+#             */
/*   Updated: 2024/11/29 23:44:48 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_xtoi(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (!str)
		return (0);
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
			return (ft_putendl_fd("Invalid hexadecimal character\n", 2), 0);
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


void	freedoublearray_point(t_points **array, int len)
{
	int	i;

	if (array != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (array[i] != NULL)
				free(array[i]);
			i++;
		}
		free(array);
		array = NULL;
	}
}

int	handle_close(t_data *data)
{
	mlx_terminate(data->mlx.mlx);
	freedoublearray_point(data->map.points, data->map.y);
	exit(0);
}

void	print_error_exit(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	freedoublearray_point(data->map.points, data->map.y);
	exit(1);
}
