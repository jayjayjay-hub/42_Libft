/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:45:53 by jtakahas          #+#    #+#             */
/*   Updated: 2024/11/03 19:15:45 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len, t_allocations **alloc)
{
	char	*newarray;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start || len == 0)
		return (newarray = malloxit(1, alloc));
	else if (len_s - start < len)
		len = len_s - start;
	newarray = (char *)malloxit((len + 1), alloc);
	if (!newarray)
		return (NULL);
	ft_strlcpy(newarray, s + start, len + 1);
	return (newarray);
}
