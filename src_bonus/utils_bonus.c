/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:30:26 by mabril            #+#    #+#             */
/*   Updated: 2024/11/13 22:10:09 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

void	ft_error(int num)
{
	if (num == 1)
	{
		ft_printf(RED "🚫 *** error ***\n" RESET);
		ft_printf(YELLOW "Try: ./server\n" RESET);
	}
	if (num == 2)
	{
		ft_printf(RED "🚫 *** error ***\n" RESET);
		ft_printf(YELLOW " 🚧 The message was broken 🚧\n" RESET);
	}
	exit(1);
}

char	*new_str(int len)
{
	char	*str;

	str = ft_calloc((len + 1), sizeof(char));
	len = strlen(str);
	if (!str)
		exit(1);
	return (str);
}
