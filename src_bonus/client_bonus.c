/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/13 23:19:28 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	g_received = 0;

void	confirm_handle(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf(RED "🚫 senal recibida\n" RESET);
		g_received = 1;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf(RED "🚫 Mensage not complete\n" RESET);
		exit(1);
	}
}

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
		usleep(300);
		bit++;
	}
}

void	ft_send_bits(int s_pid, unsigned int num, int bits)
{
	int	i;
	int	time_whait;

	i = 0;
	time_whait = 0;
	while (i < bits)
	{
		g_received = 0;
		usleep(500);
		if ((num & (1 << i)))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		while (!g_received)
		{
			usleep(500);
			while (g_received == 0)
			{
				usleep(100);
				time_whait += 100;
				if (time_whait >= 5000000)
					ft_error(2);
			}
		}
		i++;
	}
}

void	ft_send_str(int s_pid, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_send_bits(s_pid, str[i], 8);
		i++;
	}
	ft_send_bits(s_pid, '\0', 8);
	ft_printf(GREEN "✅ Message successfully, (😎 Bien joue,"
		"te mereces una fria...🍺 )\n" RESET);
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	len;
	int	client_pid;

	len = 0;
	if (ac != 3)
		ft_error(3);
	signal(SIGUSR1, confirm_handle);
	client_pid = getpid();
	server_pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	ft_send_bits_no_conf(server_pid, client_pid, 32);
	ft_send_bits(server_pid, len, 32);
	ft_send_str(server_pid, av[2], len);
	return (0);
}
