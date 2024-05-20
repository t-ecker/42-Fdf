/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:34:47 by tecker            #+#    #+#             */
/*   Updated: 2024/03/14 21:54:49 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j < n) && s2[j] && s1[i + j])
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char s1[] = "asd";
//     char s2[] = "";
//     printf("%s\n", ft_strnstr(s1, s2, 2));
//     printf("%s\n", strnstr(s1, s2, 2));
// }