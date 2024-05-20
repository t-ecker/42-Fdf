/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:21 by tecker            #+#    #+#             */
/*   Updated: 2024/03/09 18:56:58 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char *ptr;
//     char *ptr1;

//     ptr = ft_calloc(5, sizeof(char));
//     ptr = calloc(5, sizeof(char));

// }