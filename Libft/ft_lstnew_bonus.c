/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:19:48 by tecker            #+#    #+#             */
/*   Updated: 2024/05/13 20:11:56 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(int content)
{
	t_node	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ptr->value = content;
	ptr->next = NULL;
	return (ptr);
}
