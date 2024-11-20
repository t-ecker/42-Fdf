/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:34:59 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:41:11 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strwrite(int start, int end, char *ptr, const char *s1)
{
	int	i;

	i = 0;
	while (start < end + 1)
	{
		ptr[i] = s1[start];
		start++;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	ptr = malloc((end + 1 - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = ft_strwrite(start, end, ptr, s1);
	ptr[i] = '\0';
	return (ptr);
}
