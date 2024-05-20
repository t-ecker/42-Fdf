/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:34:37 by tecker            #+#    #+#             */
/*   Updated: 2024/03/14 21:52:35 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char ft_toupperr(unsigned int i, char c)
// {
//     if (c >= 'a' && c <= 'z')
//         c -= 32;
//     return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
//     char str[] = "hallo";
//     printf("%s\n", ft_strmapi(str, ft_toupperr));
// }