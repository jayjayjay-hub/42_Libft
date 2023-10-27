/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:15:45 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/27 13:25:42 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*dst_byte;
	const char	*src_byte;

	if (!dst && !src)
		return (NULL);
	dst_byte = (char *)dst;
	src_byte = (const char *)src;
	index = 0;
	while (index < n)
	{
		dst_byte[index] = src_byte[index];
		index++;
	}
	return (dst);
}
