/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:16:28 by jtakahas          #+#    #+#             */
/*   Updated: 2024/10/12 12:54:09 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	add_allocations(void *ptr, t_allocations **allocations)
{
	t_allocations	*new;

	new = malloc(sizeof(t_allocations));
	if (new == NULL)
		return (false);
	new->ptr = ptr;
	new->next = *allocations;
	*allocations = new;
	return (true);
}

void	free_allocations(t_allocations **allocations)
{
	t_allocations	*tmp;

	if (!allocations || !*allocations)
		return ;
	while (*allocations)
	{
		tmp = *allocations;
		*allocations = (*allocations)->next;
		free(tmp->ptr);
		free(tmp);
	}
}

void	*ft_malloc(size_t size, t_allocations **allocations)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		free_allocations(allocations);
		error_message("Malloc failed", NULL);
		return (NULL);
	}
	if (!add_allocations(ptr, allocations))
	{
		free(ptr);
		free_allocations(allocations);
		return (NULL);
	}
	return (ptr);
}

void	*malloxit(size_t size, t_allocations **allocations)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		free_allocations(allocations);
		error_exit("Malloc failed", NULL);
	}
	if (!add_allocations(ptr, allocations))
	{
		free(ptr);
		free_allocations(allocations);
		error_exit("Malloc failed", NULL);
	}
	return (ptr);
}
