/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:20:35 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 21:58:53 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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

void	remove_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}
