/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:28 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/27 18:47:02 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	format_check(va_list list, const char str_index)
{
	size_t	length;

	length = 0;
	if (str_index == 'c')
		length += print_char(va_arg(list, int));
	else if (str_index == 's')
		length += print_str(va_arg(list, char *));
	else if (str_index == 'p')
		length += print_ptr(va_arg(list, unsigned long long));
	else if (str_index == 'd' || str_index == 'i')
		length += print_nbr(va_arg(list, int));
	else if (str_index == 'u')
		length += print_uint(va_arg(list, unsigned int));
	else if (str_index == 'x' || str_index == 'X')
		length += print_hex(str_index, va_arg(list, unsigned int));
	else if (str_index == '%')
		length += print_char('%');
	return ((int)length);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	length_sum;
	size_t	index;

	va_start(list, str);
	length_sum = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			length_sum += format_check(list, str[index + 1]);
			index++;
		}
		else
			length_sum += print_char(str[index]);
		index++;
	}
	va_end(list);
	return ((int)length_sum);
}
