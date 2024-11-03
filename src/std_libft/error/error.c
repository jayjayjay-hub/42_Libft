/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:31:34 by jtakahas          #+#    #+#             */
/*   Updated: 2024/11/03 18:27:13 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_message(char *main_msg, char *sub_msg)
{
	ft_printf(RED"Error: %s"ENDC, main_msg);
	if (sub_msg)
		ft_printf("%s", sub_msg);
	ft_printf("\n");
}

void	error_exit(char *main_msg, char *sub_msg)
{
	error_message(main_msg, sub_msg);
	exit(1);
}

void	error_exit_free(char *main_msg, char *sub_msg,
			t_allocations *allocations)
{
	error_message(main_msg, sub_msg);
	free_allocations(&allocations);
	exit(1);
}
