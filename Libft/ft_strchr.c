/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:33:56 by tecker            #+#    #+#             */
/*   Updated: 2024/03/10 15:48:56 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (src[i] != uc && src[i])
		i++;
	if (src[i] == uc)
		return ((char *)&src[i]);
	return (NULL);
}
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char s[] = "tripouille";
//     printf("%s\n", ft_strchr(s, 't' + 256));
//     printf("%s\n", strchr(s, 't' + 256));
// }