/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:34:29 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:40:49 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(char const *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     printf("%zu\n", ft_strlen("a"));
//     printf("%zu\n", strlen("a"));
//     return (1);
// }