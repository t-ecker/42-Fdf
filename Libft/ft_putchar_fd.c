/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:33:31 by tecker            #+#    #+#             */
/*   Updated: 2024/03/09 19:06:25 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
//     int fd;
//     fd = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     ft_putchar_fd('A', fd);
//     close (fd);
//     return (0);
// }