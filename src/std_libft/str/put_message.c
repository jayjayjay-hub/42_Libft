/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:27:57 by jtakahas          #+#    #+#             */
/*   Updated: 2024/06/09 18:38:59 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_message(char *main_message, char *sub_message)
{
	ft_printf("%s", main_message);
	if (sub_message)
		ft_printf(" (%s)", sub_message);
	ft_printf("\n");
}
