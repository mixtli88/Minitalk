/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:30:26 by mabril            #+#    #+#             */
/*   Updated: 2024/11/13 22:12:24 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_error(int num)
{
	if (num == 1)
	{
		ft_printf(RED "error\n" RESET);
		ft_printf(YELLOW "Try: ./server\n" RESET);
	}
	if (num == 2)
	{
		ft_printf(RED "error\n" RESET);
		ft_printf(YELLOW "The message was broken\n" RESET);
	}
	if (num == 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
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
