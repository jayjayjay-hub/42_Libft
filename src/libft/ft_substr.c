/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:45:53 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/27 15:24:18 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newarray;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start || len == 0)
		return (newarray = ft_calloc(1, 1));
	else if (len_s - start < len)
		len = len_s - start;
	newarray = (char *)malloc((len + 1));
	if (!newarray)
		return (NULL);
	ft_strlcpy(newarray, s + start, len + 1);
	return (newarray);
}
