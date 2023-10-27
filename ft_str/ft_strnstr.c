/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:15:10 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/26 13:57:25 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[n])
		{
			while (haystack[i + n] == needle[n] && (i + n) < len)
			{
				if (needle[n + 1] == '\0')
					return ((char *)(haystack + i));
				n++;
			}
			n = 0;
		}
		i++;
	}
	return (NULL);
}
