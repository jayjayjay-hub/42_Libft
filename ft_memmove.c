/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:44:11 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/06 18:33:27 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dst_str;
	const char	*src_str;

	if (!dst && !src)
		return (NULL);
	dst_str = (char *)dst;
	src_str = (const char *)src;
	if (dst <= src)
	{
		while (n--)
			*dst_str++ = *src_str++;
	}
	else
	{
		dst_str += n;
		src_str += n;
		while (n--)
			*--dst_str = *--src_str;
	}
	return (dst);
}
