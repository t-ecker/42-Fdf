/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:41 by tecker            #+#    #+#             */
/*   Updated: 2024/03/09 18:59:51 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     char c = '1';
//     printf("%d\n", ft_isdigit(c));
//     printf("%d\n", isdigit(c));
//     return (0);
// }