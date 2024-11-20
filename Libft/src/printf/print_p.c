/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:10:49 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 13:20:44 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putpointerhex(unsigned long n)
{
	int		len;
	char	*digits_low;

	len = 0;
	digits_low = "0123456789abcdef";
	if (n == 0)
	{
		len += ft_putstr("0x");
		return (len);
	}
	len += ft_putpointerhex(n / 16);
	len += ft_putchar(digits_low[n % 16]);
	return (len);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
		return (ft_putstr("0x0"));
	return (ft_putpointerhex(n));
}
