/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:30:07 by tecker            #+#    #+#             */
/*   Updated: 2024/05/13 20:18:42 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

struct s_Node
{
	int				value;
	int				pos;
	struct s_Node	*next;
};
typedef struct s_Node	t_node;

long		ft_atoi(const char *str);
void		*ft_bzero(void *str, size_t len);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(void *s1, void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, void *src, size_t n);
void		*ft_memset(void *str, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *src, int c);
char		*ft_strdup(char *s1);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t destsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlen(char const *src);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *src, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

void		ft_lstiter(t_node *lst, void (*f)(int));
void		ft_lstadd_back(t_node **lst, t_node *new);
void		ft_lstclear(t_node **lst, void (*del)(int));
void		ft_lstdelone(t_node *lst, void (*del)(int));
void		ft_lstiter(t_node *lst, void (*f)(int));
t_node		*ft_lstlast(t_node *lst);
t_node		*ft_lstnew(int content);
int			ft_lstsize(t_node *lst);
void		ft_lstadd_front(t_node **lst, t_node *new);
t_node		*ft_lstmap(t_node *lst, void *(*f)(int), void (*del)(int));
char		*get_next_line(int fd);

#endif