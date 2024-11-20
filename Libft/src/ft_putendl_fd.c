/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:33:37 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:40:25 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
//     int fd;
//     char str[] = "Hallo";
//     fd = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     ft_putendl_fd(str, fd);
//     close (fd);
//     return (0);
// }