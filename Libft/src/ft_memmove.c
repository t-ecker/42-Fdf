/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:33:19 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:40:16 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	outsource(int i, char *d, char *s, size_t n)
{
	i = 0;
	while (i < (int)n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		outsource(i, d, s, n);
	}
	return (d);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[] = "Hallo stop";
//     char str2[] = "Hallo stop";
//     ft_memmove(str2, str2 + 2, 5);
//     printf("%s\n", str2);

//     memmove(str1, str1 + 2, 5);
//     printf("%s\n", str1);
// }