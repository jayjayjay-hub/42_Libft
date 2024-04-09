/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:46:06 by jtakahas          #+#    #+#             */
/*   Updated: 2024/04/09 09:50:35 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr_gnl(char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (char)c)
			return (str + index);
		index++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc(sizeof(char) * ((ft_strlen_gnl(str) + ft_strlen_gnl(buf)) + 1));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buf[j])
		new_str[i++] = buf[j++];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
