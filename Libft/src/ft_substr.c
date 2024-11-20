/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:35:04 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:41:14 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	slen;
	size_t	finish;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	finish = slen - start;
	if (len < finish)
		finish = len;
	ptr = malloc(sizeof(char) * (finish + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < finish && s[start])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
//     char str[] = "0123456789";
//     printf("%s\n", ft_substr(str, 5, 7));
//     return (0);
// }