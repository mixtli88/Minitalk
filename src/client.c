/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/05 19:14:18 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
void ft_send_bit(int pid, char c)
{
	int bit;
	
	bit =0;
	while(bit < 8)
	{
		if((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;	
	}
}

int	main(int ac, char **av)
{
	int pid;
	int i;

	i = 0;
	if(ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_send_bit(pid, av[2][i]);
			i++;
		}	
		ft_send_bit(pid, '\n');
	}
	else
	{
		printf("\033[91mError: wrong format.\033[0m\n");
		printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}
