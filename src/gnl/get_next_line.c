/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:14:26 by jtakahas          #+#    #+#             */
/*   Updated: 2024/05/09 17:27:13 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*new_file_str(char *file_str)
{
	size_t	i;
	size_t	j;
	char	*new_file_str;

	i = 0;
	j = 0;
	while (file_str[i] && file_str[i] != '\n')
		i++;
	if (!file_str[i])
	{
		free(file_str);
		return (NULL);
	}
	new_file_str = malloc(sizeof(char) * ((gnl_strlen(file_str) - i) + 1));
	if (!new_file_str)
	{
		free(file_str);
		return (NULL);
	}
	i++;
	while (file_str[i])
		new_file_str[j++] = file_str[i++];
	new_file_str[j] = '\0';
	free(file_str);
	return (new_file_str);
}

static char	*input_line(char *file_str)
{
	size_t	index;
	char	*next_line;

	index = 0;
	if (!file_str[index])
		return (NULL);
	while (file_str[index] && file_str[index] != '\n')
		index++;
	next_line = malloc(sizeof(char) * (index + 2));
	if (!next_line)
		return (NULL);
	index = 0;
	while (file_str[index] && file_str[index] != '\n')
	{
		next_line[index] = file_str[index];
		index++;
	}
	if (file_str[index] == '\n')
	{
		next_line[index] = '\n';
		index++;
	}
	next_line[index] = '\0';
	return (next_line);
}

static char	*read_file_str(int fd, char *file_str)
{
	char	*buf;
	ssize_t	read_byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(file_str);
		return (NULL);
	}
	read_byte = 1;
	while (file_str && read_byte && (gnl_strchr(file_str, '\n') == NULL))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			free(file_str);
			return (NULL);
		}
		buf[read_byte] = '\0';
		file_str = gnl_strjoin(file_str, buf);
	}
	free(buf);
	return (file_str);
}

char	*get_next_line(int fd)
{
	static char	*file_str[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file_str[fd])
	{
		file_str[fd] = (char *)malloc(sizeof(char *) * 1);
		if (!file_str[fd])
			return (NULL);
		file_str[fd][0] = '\0';
	}
	file_str[fd] = read_file_str(fd, file_str[fd]);
	if (!file_str[fd])
		return (NULL);
	next_line = input_line(file_str[fd]);
	file_str[fd] = new_file_str(file_str[fd]);
	return (next_line);
}
