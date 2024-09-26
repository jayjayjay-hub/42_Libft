/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:31:34 by jtakahas          #+#    #+#             */
/*   Updated: 2024/09/26 19:08:17 by jtakahas         ###   ########.fr       */
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
