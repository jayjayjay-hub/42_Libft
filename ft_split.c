/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:53:47 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/06 18:41:57 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

static size_t	ft_words_count(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_input_word(char *word, char const *s, size_t end_word,
	size_t len_word)
{
	size_t	j;

	j = 0;
	while (len_word > 0)
	{
		word[j] = s[end_word - len_word];
		j++;
		len_word--;
	}
	word[j] = '\0';
	return ;
}

static char	**ft_words_split(char const *s, char c,
	char **newarray, size_t num_words)
{
	size_t	i;
	size_t	word;
	size_t	len_word;

	i = 0;
	word = 0;
	len_word = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len_word++;
		}
		newarray[word] = (char *)malloc(sizeof(char) * (len_word + 1));
		if (!newarray)
			return (free_array(newarray, word));
		ft_input_word(newarray[word], s, i, len_word);
		len_word = 0;
		word++;
	}
	newarray[word] = 0;
	return (newarray);
}

char	**ft_split(char const *s, char c)
{
	char	**newarray;
	size_t	num_words;

	if (!s)
		return (0);
	num_words = ft_words_count(s, c);
	newarray = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!newarray)
		return (0);
	newarray = ft_words_split(s, c, newarray, num_words);
	return (newarray);
}
