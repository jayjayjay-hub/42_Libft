/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:46:56 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/27 17:09:11 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len_s;
	char			*newarray;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	newarray = (char *)malloc(len_s + 1);
	if (!newarray)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		newarray[i] = (*f)(i, s[i]);
		i++;
	}
	newarray[i] = '\0';
	return (newarray);
}
