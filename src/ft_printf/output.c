/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:24:18 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/02 19:52:42 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	if (!str)
	{
		print_str("(null)");
		return (LEN_NULL_STR);
	}
	else
	{
		write(1, str, ft_strlen(str));
		return ((int)ft_strlen(str));
	}
}

int	print_nbr(int nbr)
{
	int		len_nbr;
	char	*str_nbr;

	str_nbr = ft_itoa(nbr);
	len_nbr = print_str(str_nbr);
	free(str_nbr);
	return (len_nbr);
}

int	print_uint(unsigned int nbr)
{
	int		len_nbr;
	char	*str_nbr;

	str_nbr = unsigned_itoa(nbr);
	len_nbr = print_str(str_nbr);
	free(str_nbr);
	return (len_nbr);
}
