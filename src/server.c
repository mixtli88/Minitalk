/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/06 20:41:03 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void ft_handler(int sig)
{
	static int bit;
	static int char_bin;

	if (sig == SIGUSR1)
		char_bin |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", char_bin);
		bit = 0;
		char_bin = 0;
	}
}
int	main(int ac, char **av)
{
	int pid;
	
	if(ac != 1 && av)
	{
		printf(RED "error\n" RESET);
		printf(YELLOW "Try: ./server\n" RESET);
	}
	else
	{
		pid = getpid();
		printf( BLUE "%s" CYAN "%s" RESET "%d\n", "PID",  " -> ", pid);
		while (1)
		{
			signal(SIGUSR1, ft_handler);
			signal(SIGUSR2, ft_handler);
			pause();
		}	
	}
	return (0);
}
