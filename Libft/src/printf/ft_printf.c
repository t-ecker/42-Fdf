/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:11:00 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 13:21:29 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(int i, int b)
{
	static int	result;

	if (b == 1)
		result = 1;
	if (i == -1 || result == -1)
		result = -1;
	else
		result = 1;
	return (result);
}

int	print_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *a, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, a);
	check(1, 1);
	while (a[++i])
	{
		if (a[i] == '%')
		{
			len += print_arg(a[++i], args);
			if (check(1, 0) == -1)
				return (va_end(args), -1);
		}
		else
		{
			if (check(ft_putchar(a[i]), 0) == -1)
				return (va_end(args), -1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("\n	%i\n", ft_printf("%%c"));
// 	printf("\n	%i\n", printf("%%c"));
// 	return (0);
// }
