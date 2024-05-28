#include "../fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_is_format(char *str, char *format)
{
	if (ft_strnstr(str, format, ft_strlen(str)) == NULL)
		return (0);
	return (1);
}

int	ft_is_readable(char *file)
{
	int	fd;
	int	res;

	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		res = 0;
	else
		res = 1;
	close(fd);
	return (res);
}

int	get_size(char **array)
{
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}
