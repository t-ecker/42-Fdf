/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:18:37 by tecker            #+#    #+#             */
/*   Updated: 2024/04/08 17:39:51 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
// # include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *src, int c);
size_t	ft_strlen(char const *src);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif