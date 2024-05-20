/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:58 by tecker            #+#    #+#             */
/*   Updated: 2024/03/14 22:08:24 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char *str = "asna";
//     int b = 6;
// 	char c = 'n';
//     printf("%s\n", ft_memchr(str, c, b));
//     printf("%s\n", memchr(str, c, b));
// }