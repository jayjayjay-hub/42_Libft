/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:31:34 by jtakahas          #+#    #+#             */
/*   Updated: 2024/09/29 00:11:39 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_message(char *main_msg, char *sub_msg)
{
	printf(RED"Error: %s"ENDC, main_msg);
	if (sub_msg)
		printf("%s", sub_msg);
	printf("\n");
}

void	error_exit(char *main_msg, char *sub_msg)
{
	error_message(main_msg, sub_msg);
	exit(1);
}
