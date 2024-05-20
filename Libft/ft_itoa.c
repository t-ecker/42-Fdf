/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:32:53 by tecker            #+#    #+#             */
/*   Updated: 2024/03/14 21:16:41 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int	digits;
	int	minus;

	minus = n < 0;
	digits = 0;
	if (n == 0)
		digits++;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	digits += minus;
	return (digits);
}

static char	*ft_writenbr(char *ptr, int n, int c, int i)
{
	int	len;

	len = digits(n);
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
		c++;
	}
	while (i >= c)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		c;

	c = 0;
	i = digits(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = malloc(digits(n) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_writenbr(ptr, n, c, i);
	return (ptr);
}
// #include <stdio.h>
// int main(void)
// {
//    int number = -2147483648;
//     printf("%s\n", ft_itoa(number));
//     return (1);
// }