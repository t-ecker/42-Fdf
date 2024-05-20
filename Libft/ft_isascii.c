/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:36 by tecker            #+#    #+#             */
/*   Updated: 2024/03/09 18:59:25 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     char c = 128;
//     printf("%c\n", c);
//     printf("%d\n", ft_isascii(c));
//     printf("%d\n", isascii(c));
//     return (0);
// }