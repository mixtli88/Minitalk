/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/05 19:27:19 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void ft_handler(int sig)
{
	static int bit;
	static int i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
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
