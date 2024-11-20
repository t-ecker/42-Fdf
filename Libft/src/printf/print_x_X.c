/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:51 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 13:20:53 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ab(unsigned int n, char c)
{
	int		len;
	char	*digits_low;
	char	*digits_up;

	len = 0;
	digits_up = "0123456789ABCDEF";
	digits_low = "0123456789abcdef";
	if (n == 0)
	{
		return (len);
	}
	len += ab(n / 16, c);
	if (c >= 'A' && c <= 'Z')
		len += ft_putchar(digits_up[n % 16]);
	else
		len += ft_putchar(digits_low[n % 16]);
	return (len);
}

int	ft_puthex(int n, char c)
{
	unsigned int	m;

	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		m = (unsigned int)n;
		return (ab(m, c));
	}
	return (ab(n, c));
}
