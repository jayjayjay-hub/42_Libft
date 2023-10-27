/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:43 by jtakahas          #+#    #+#             */
/*   Updated: 2023/08/27 12:10:44 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char str_i, int sign, long ans)
{
	if (ans == LONG_MAX / 10 && sign == 1)
	{
		if ('8' <= str_i && str_i <= '9')
			return (1);
	}
	else if (ans > LONG_MAX / 10 && sign == 1)
		return (1);
	else if (ans == LONG_MAX / 10 && sign == -1 && (str_i == '9'))
		return (2);
	else if (ans > LONG_MAX / 10 && sign == -1)
		return (2);
	return (0);
}

long	ft_strtol(const char *str, int sign)
{
	long	ans;
	int		n;

	n = 0;
	ans = 0;
	while (ft_isdigit(str[n]))
	{
		if (ft_check(str[n], sign, ans) == 1)
			return (LONG_MAX);
		else if (ft_check(str[n], sign, ans) == 2)
			return (LONG_MIN);
		ans = (str[n] - 48) + (ans * 10);
		n++;
	}
	return (ans * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return ((int)ft_strtol(str, sign));
}
