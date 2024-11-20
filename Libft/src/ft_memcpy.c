/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:33:10 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:40:13 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while ((i < n))
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char str1[] = "";
//     char str2[] = "";
//     char str3[] = "Hallo stop";

//     ft_memcpy(str2, str2 + 6, 1);
//     printf("%s\n", str2);

//     memcpy(str1, str1 + 6, 1);
//     printf("%s\n", str1);
//     memmove(str3, str3 + 2, 5);
//     printf("%s\n", str3);
//     return (0);
// }