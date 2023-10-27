/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:55:18 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/28 15:46:09 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newarray;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newarray = (char *)malloc(sizeof(char) * (len + 1));
	if (!newarray)
		return (NULL);
	ft_strlcpy(newarray, s1, len + 1);
	ft_strlcat(newarray, s2, len + 1);
	return (newarray);
}
