/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:53:17 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/26 13:53:29 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_putnbr_fd(int n, int fd)
// {
// 	ft_putstr_fd(ft_itoa(n), fd);
// }

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		ft_putchar_fd('-', fd);
		n_long *= -1;
	}
	if (n_long >= 10)
	{
		ft_putnbr_fd(n_long / 10, fd);
		ft_putchar_fd(n_long % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n_long + '0', fd);
}
