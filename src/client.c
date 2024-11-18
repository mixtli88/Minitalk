/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/17 22:01:18 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	g_received = 0;

void	confirm_handle(int sig)
{
	
	if (sig == SIGUSR1)
		g_received = 1;
	else if (sig == SIGUSR2)
		exit(1);
}


void	ft_send_bits_no_conf(int s_pid, unsigned int num, int bits)
{
	int	bit;

	bit = 0;
	while (bit < bits)
	{
		if ((num & (1 << bit)))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(1000);
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
		if ((num & (1 << i)))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		while (!g_received)
		{
			usleep(1000);
			while (g_received == 0)
			{
				usleep(1000);
				time_whait += 100;
				if (time_whait >= 2000000)
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
		// ft_printf("i = %d\n", i);  
		ft_send_bits(s_pid, str[i], 8);
		i++;
	}
	// ft_printf("\uF464\n");
	ft_send_bits(s_pid, '\0', 8);
}
void handle_sigint(int sig)
{
	static int s_pid;

    (void)sig;
	if (sig == g_received)
		s_pid = sig;
    if ( sig == SIGINT)
    {
		printf("server_pid %d\n", s_pid);
       	ft_send_bits(s_pid, 65535, 32);
		exit(1); 
    }  
}
int	main(int ac, char **av)
{
	int	server_pid;
	int	len;
	int	client_pid;

	len = 0;
	if (ac != 3)
		ft_error(3);
	client_pid = getpid();	
	server_pid = ft_atoi(av[1]);
	g_received = server_pid;
	handle_sigint(server_pid);
	g_received = 0;
	
	signal(SIGUSR1, confirm_handle);
	signal(SIGINT, handle_sigint);
	// printf("e3e3e%d\", client_pid);
	len = ft_strlen(av[2]);
	printf("len = %d\n", len);
	ft_send_bits_no_conf(server_pid, client_pid, 32);
	ft_send_bits(server_pid, len, 32);
	ft_send_str(server_pid, av[2], len);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int	server_pid;
// 	int	len;
// 	int	client_pid;

// 	len = 0;
// 	if (ac != 3)
// 		ft_error(3);
// 	signal(SIGUSR1, confirm_handle);
// 	client_pid = getpid();
// 	// printf("e3e3e%d\", client_pid);
// 	server_pid = ft_atoi(av[1]);
// 	len = ft_strlen(av[2]);
// 	ft_send_bits_no_conf(server_pid, client_pid, 32);
// 	ft_send_bits(server_pid, len, 32);
// 	ft_send_str(server_pid, av[2], len);
// 	return (0);
// }



