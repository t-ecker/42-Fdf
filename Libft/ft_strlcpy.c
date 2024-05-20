/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:34:24 by tecker            #+#    #+#             */
/*   Updated: 2024/03/14 21:52:05 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize > 0)
	{
		while (src[i] && i < (destsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char dest1[1] = "";
//     char dest2[1] = "";

//     char *src = "hallo";
//     printf("%zu\n", ft_strlcpy(dest1, src, 1));
//     printf("%lu\n", strlcpy(dest2, src, 1));
//     printf("%s\n", dest1);
//     printf("%s\n", dest2);

// }