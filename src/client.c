/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/11 21:14:35 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int s_received = 0;

void confirm_handle(int sig)
{
	if(sig == SIGUSR1)
	{
		
		// ft_printf("signal confirme\n");
		s_received = 1;
	}
	else if(sig == SIGUSR2)
	{
		// ft_printf("Mensage not complete\n");
		exit(0);
	}
}

void ft_send_bits_no_conf(int pid, unsigned int num, int bits)
{
    int bit;
    
    bit = 0;
    while (bit < bits)
    {
        if ((num & (1 << bit)))
		{
			// ft_printf("bit %d = 1\n", bit);	
            kill(pid, SIGUSR1);
		}
        else
		{
			// ft_printf("bit %d = 0\n", bit);
            kill(pid, SIGUSR2);
		}
        usleep(100);
        bit++;
    }
}

void	ft_send_bits(int s_pid, unsigned int num, int bits)
{
	int	i;
	int b;
	
	b = 1;
	i = 0;
	
	while (i < bits)
	{
		s_received = 0;
		if ((num & (1 << i)))
		{
			// ft_printf("bit %d - %d = 1\n", i,b);
			kill(s_pid, SIGUSR1);
		}
		else
		{
			kill(s_pid, SIGUSR2);
			// ft_printf("bit %d - %d = 0\n", i,b);
			
		}
		b= b*2;
		while(!s_received)
			usleep(100);
		i++;
	}
	// ft_printf(" Message arrive\n");

	
	// if(s)
	// ft_printf(" c = %c\n", c);
}

void	ft_send_str(int s_pid, char *str, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
		// ft_printf(" str[%d] = %c\n",i, str[i]);
        ft_send_bits(s_pid, str[i], 8);  // Enviamos 8 bits por carácter
        i++;
    }
	ft_send_bits(s_pid, '\0', 8);
	// ft_printf(" Message arrive\n");
}
// void	ft_send_str(int pid, char *str, int len)
// {
// 	int	bit;
// 	int b;
// 	int i;

// 	b =1;
// 	bit = 0;
// 	ft_printf(" c = %c\n", c);
// 	while (bit < 8)
// 	{
// 		if ((c & (1 << bit)) != 0)
// 		{
// 			ft_printf("bit %d - %d = 1\n", bit,b);
// 			kill(pid, SIGUSR1);
// 		}
// 		else
// 		{
// 			ft_printf("bit %d - %d = 0\n", bit,b);
// 			kill(pid, SIGUSR2);
// 		}
// 		b= b*2;
// 		usleep(100);
// 		bit++;
// 	}
// 	ft_printf(" %c cararter enviado\n", c);
// }

int	main(int ac, char **av)
{
	int	server_pid;
	// int	i;
	int	len;
	int client_pid;

	// i = 0;
	len = 0;
	if (ac != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	signal(SIGUSR1, confirm_handle);
	client_pid = getpid();
	server_pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	ft_send_bits_no_conf(server_pid, client_pid, 32);
	// ft_printf("c_pid %d \n\n\n", client_pid);
	ft_send_bits(server_pid, len, 32);
	// ft_printf("len %d \n\n\n", len);
	ft_send_str(server_pid, av[2], len);
	
	ft_printf(" Message arrive\n");
	return (0);
}
