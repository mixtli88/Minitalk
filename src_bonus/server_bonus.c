/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/13 23:22:23 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	g_state = 0;

int	ft_client_pid(int sig)
{
	static int			bit;
	static unsigned int	num;
	int					tem;

	tem = 0;
	if (sig == SIGUSR1)
		num |= (1u << bit);
	bit++;
	if (bit == 32)
	{
		ft_printf("cantidad de bit de pid cliente ok\n");
		tem = num;
		num = 0;
		bit = 0;
		g_state = 1;
		return (tem);
	}
	usleep(300);
	return (num);
}

char	*ft_handler_size(int sig)
{
	static int			bit;
	static unsigned int	num;
	char				*str;

	str = NULL;
	if (sig == SIGUSR1)
		num |= (1u << bit);
	bit++;
	ft_printf("bit de len = %d\n", bit);
	if (bit == 32)
	{
		ft_printf("cantidad de bit de len cliente ok\n");
		str = new_str(num);
		g_state = 2;
		bit = 0;
		num = 0;
		return (str);
	}
	return (str);
}

char	*ft_handler_char(int sig, char *str)
{
	static int	bit;
	static int	c;
	static int	i;

	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (sig == 3)
		c = '\0';
	if (bit == 8 || sig == 3)
	{
		str[i++] = c;
		if (c == '\0')
		{
			if (sig != 3)
				ft_printf("%s\n", str);
			free(str);
			str = NULL;
			g_state = 0;
			i = 0;
		}
		bit = 0;
		c = 0;
	}
	return (str);
}

void	ft_handler(int sig)
{
	static char			*str;
	static unsigned int	c_pid;

	if (g_state == 0)
		c_pid = ft_client_pid(sig);
	else if (g_state == 1)
	{
		str = ft_handler_size(sig);
		usleep(10000);
		if (c_pid)
			kill(c_pid, SIGUSR1);
	}
	else if (g_state == 2)
	{
		str = ft_handler_char(sig, str);
		usleep(10000);
		if (c_pid)
			kill(c_pid, SIGUSR1);
		if (sig == 3 || g_state == 0)
			c_pid = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	time_whait;

	time_whait = 0;
	if (ac != 1 && av)
		ft_error(1);
	pid = getpid();
	ft_printf(BLUE "%s" CYAN "%s" RESET "%d\n", "PID", " -> ", pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		time_whait = 0;
		usleep(300);
	// 	while (g_state == 2)
	// 	{
	// 		usleep(100);
	// 		time_whait += 100;
	// 		if (time_whait >= 2000000)
	// 			ft_handler(3);
	// 	}
	}
	return (0);
}
