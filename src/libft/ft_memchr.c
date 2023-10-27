/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:57:24 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/27 14:11:47 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_index;

	index = 0;
	s_index = (unsigned char *)s;
	while (index < n)
	{
		if (s_index[index] == (unsigned char)c)
			return ((void *)(s_index + index));
		index++;
	}
	return (NULL);
}
