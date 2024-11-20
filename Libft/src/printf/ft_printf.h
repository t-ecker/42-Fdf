/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:27:21 by tecker            #+#    #+#             */
/*   Updated: 2024/11/20 13:21:35 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

#include "../../libft.h"

int	ft_putnbr(int n);
int	ft_putpointer(void *ptr);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(char *c);
int	ft_puthex(int n, char c);
int	ft_printf(const char *a, ...);
int	ft_putchar(char c);
int	check(int i, int b);

#endif