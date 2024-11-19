/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:30:26 by mabril            #+#    #+#             */
/*   Updated: 2024/11/18 18:44:34 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

void	ft_send_bits_no_conf(int pid, unsigned int num, int bits)
{
	int	bit;

	bit = 0;
	while (bit < bits)
	{
		if ((num & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
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
	if (num == 3)
	{
		ft_printf(RED " 🚫 *** Error: wrong format.\n"RESET);
		ft_printf(YELLOW "Try: ./client <PID> <MESSAGE>\n"RESET);
	}
	exit(1);
}
