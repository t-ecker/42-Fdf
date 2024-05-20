/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:35:17 by tecker            #+#    #+#             */
/*   Updated: 2024/03/14 20:37:11 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     printf("%c\n", ft_toupper('!'));
//     printf("%c\n", toupper('!'));
// }