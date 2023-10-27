/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:16:31 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/06 18:22:56 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	char	*newarray;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check_set(*s1, set) == 1)
			s1++;
		else
			break ;
	}
	len_s1 = ft_strlen(s1);
	while (len_s1 != 0)
	{
		if (ft_check_set(s1[len_s1 - 1], set) == 1)
			len_s1--;
		else
			break ;
	}
	newarray = (char *)malloc(len_s1 + 1);
	if (!newarray)
		return (NULL);
	ft_strlcpy(newarray, (char *)s1, len_s1 + 1);
	return (newarray);
}
