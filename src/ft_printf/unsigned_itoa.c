/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:38 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/02 20:02:11 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_to_char(char *str, unsigned int number, int len)
{
	str[len] = '\0';
	len--;
	if (number == 0)
		str[0] = '0';
	while (number > 0)
	{
		str[len] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	return ;
}

static int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*unsigned_itoa(unsigned int nbr)
{
	char			*str;
	int				len_nbr;

	len_nbr = ft_nbrlen(nbr);
	str = (char *)malloc((len_nbr + 1));
	if (!(str))
		return (NULL);
	ft_to_char(str, nbr, len_nbr);
	return (str);
}
