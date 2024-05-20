/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:26 by tecker            #+#    #+#             */
/*   Updated: 2024/03/09 18:58:41 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || ((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')));
}
// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     char c = '=';
//     printf("%d\n", ft_isalnum(c));
//     printf("%d\n", isalnum(c));
//     return (0);
// }