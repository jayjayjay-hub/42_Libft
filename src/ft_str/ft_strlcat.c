/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:25 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/04 11:54:19 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	n;

	if (!dstsize)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dst = ft_strlen((const char *)dst);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	n = len_dst;
	i = 0;
	while (src[i] && n + 1 < dstsize)
	{
		dst[n] = src[i];
		i++;
		n++;
	}
	dst[n] = '\0';
	return (len_dst + len_src);
}
