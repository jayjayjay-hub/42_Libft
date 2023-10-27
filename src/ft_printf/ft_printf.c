/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:28 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/02 19:35:43 by jtakahas         ###   ########.fr       */
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

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int	test1;
// 	int	test2;
// 	int	test3;
// 	int	test4;
// 	int	test5;
// 	int	test6;
// 	int	test7;
// 	int	test8;
// 	int	test9;
// 	int	test10;

// 	ft_printf("ft_printf:\n");
// 	test1 = ft_printf("Hello World!\n");
// 	test2 = ft_printf("Hello %s!\n", "World");
// 	test3 = ft_printf("Hello %d!\n", 42);
// 	test4 = ft_printf("Hello %p!\n", &test1);
// 	test5 = ft_printf("Hello %x!\n", 42);
// 	test6 = ft_printf("Hello %X!\n", 42);
// 	test7 = ft_printf("Hello %c!\n", 'c');
// 	test8 = ft_printf("Hello %%!\n");
// 	test9 = ft_printf("Hello %u!\n", 42);
// 	test10 = ft_printf("null -> %s\n", NULL);
// 	ft_printf("\nprintf:\n");

// 	return (0);
// }
