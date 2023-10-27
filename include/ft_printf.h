/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:48 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/02 19:42:22 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LEN_NULL_STR 6

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_str(char *str);
int		print_nbr(int nbr);
int		print_char(int c);
int		print_ptr(unsigned long long ptr);
int		print_uint(unsigned int nbr);
int		print_hex(const char format, unsigned int nbr);
char	*unsigned_itoa(unsigned int nbr);

#endif
