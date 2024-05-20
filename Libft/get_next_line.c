/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:55:43 by tecker            #+#    #+#             */
/*   Updated: 2024/04/09 14:24:05 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_new_rest(char *c)
{
	int		len;
	char	*new;

	len = ft_strchr(c, '\n') - c;
	new = ft_substr(c, len + 1, ft_strlen(c));
	free(c);
	if (new == NULL)
		return (NULL);
	if (new[0] == '\0')
		return (free(new), NULL);
	return (new);
}

char	*search_for_nl(char *c)
{
	int		len;
	char	*new;

	len = ft_strchr(c, '\n') - c;
	new = ft_substr(c, 0, len + 1);
	if (new == NULL)
		return (NULL);
	if (new[0] == '\0')
		return (free(new), NULL);
	return (new);
}

char	*read_from_file(int fd, char *rest)
{
	char	*buffer;
	int		bytesread;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (free(rest), NULL);
	bytesread = 1;
	while (!ft_strchr(rest, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free (rest);
			return (free(buffer), NULL);
		}
		buffer[bytesread] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (rest == NULL)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest == NULL)
		rest = ft_strdup("");
	if (rest == NULL)
		return (NULL);
	rest = read_from_file(fd, rest);
	if (rest == NULL)
		return (NULL);
	line = search_for_nl(rest);
	if (!line)
	{
		if (rest != NULL)
		{
			free(rest);
			rest = NULL;
		}
		return (NULL);
	}
	rest = find_new_rest(rest);
	return (line);
}

// #include <stdio.h>
// int main(void)
// {
//     int fd;
//     char *str;
//     fd = open("text.txt", O_RDONLY);
// 	for (int i = 0; i < 6; i++)
// 	{
// 		str = get_next_line(fd);
// 		printf("output:	%s|", str);
//         free (str);
// 	}
//     close (fd);
//     return (0);
// }