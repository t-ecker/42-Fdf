/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:15:59 by tecker            #+#    #+#             */
/*   Updated: 2024/05/30 18:16:20 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char const *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	ptr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (ptr == NULL)
		return (free(s1), NULL);
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (free(s1), ptr);
}

char	*ft_strchr_gnl(const char *src, int c)
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

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen_gnl(s1);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	slen;
	size_t	finish;

	i = 0;
	slen = ft_strlen_gnl(s);
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup_gnl(""));
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
