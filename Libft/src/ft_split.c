/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:08:20 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 00:40:32 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	num_splits(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free(int a1, char **str)
{
	while (a1 > 0)
	{
		free(str[a1 - 1]);
		a1--;
	}
	free(str);
	return (NULL);
}

static void	*split2(const char *s, char c, char **str)
{
	int	j;
	int	a2;
	int	a1;
	int	len;

	j = 0;
	a1 = 0;
	while (a1 < num_splits(s, c))
	{
		len = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j + len] && s[j + len] != c)
			len++;
		str[a1] = malloc(sizeof(char) * (len + 1));
		if (str[a1] == NULL)
			return (ft_free(a1, str));
		a2 = 0;
		while (len--)
			str[a1][a2++] = s[j++];
		str[a1][a2] = '\0';
		a1++;
	}
	str[a1] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (num_splits(s, c) + 1));
	if (str == NULL)
		return (NULL);
	return (split2(s, c, str));
}

// #include <stdio.h>
// int main(void)
// {
//     char *input_string = "Hallo";
// 	// *input_string ;
//     char delimiter = 0;
//     char **tab;
// 	tab = ft_split(input_string, delimiter);
// 	// printf("%s\n", tab);
//     // printf("%i\n", len(tab, d));
//     // printf("%i\n", num_splits(tab, d));
//     int i = 0;
//     char **result = ft_split(input_string, delimiter);
//     while (i < num_splits(input_string, delimiter))
//     {
//         printf("%s\n", result[i]);
//         i++;
//     }
// 	// printf("%s\n", tab[0]);
//     free(result);
//     return (0);
// }