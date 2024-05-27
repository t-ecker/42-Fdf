#include "../fdf.h"

int	ft_xtoi(char *str, t_data *data)
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
		else if (str[i] != '\n')
			print_error_exit("Invalid hexadecimal character", data);
		i++;
	}
	return (num);
}

void	freedoublearray(char **array)
{
	int	i;

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
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	freedoublearray_int(data->map.z, data);
	freedoublearray_int(data->color.map_color, data);
	exit(1);
}

void	print_error_exit(char *str, t_data *data)
{
	perror(str);
	handle_close(data);
}
