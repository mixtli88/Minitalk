/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/20 13:29:36 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// // *** ENGLISH ***
// // Global variable to manage communication state
// // *** ESPAÑOL ***
// // Variable global para gestionar el estado de la comunicación
// // *** FRANÇAIS ***
// // Variable globale pour gérer l'état de la communication
// static int g_state = 0;

// // *** ENGLISH ***
// // Handles client PID transmission (32 bits)
// // *** ESPAÑOL ***
// // Maneja la transmisión del PID del cliente (32 bits)
// // *** FRANÇAIS ***
// // Gère la transmission du PID client (32 bits)
// int ft_client_pid(int sig)
// {
//     static int bit = 0;
//     static unsigned int num = 0;
//     int tem = 0;

//     if (sig == SIGUSR1)
//         num |= (1u << bit); // Add bit to the PID
//     bit++;
//     if (bit == 32) // Full PID received
//     {
//         tem = num;
//         num = 0;
//         bit = 0;
//         g_state = 1; // Move to next state
//         return (tem);
//     }
//     usleep(100);
//     return (num);
// }

// // *** ENGLISH ***
// // Handles message size reception (32 bits)
// // *** ESPAÑOL ***
// // Maneja la recepción del tamaño del mensaje (32 bits)
// // *** FRANÇAIS ***
// // Gère la réception de la taille du message (32 bits)
// char *ft_handler_size(int sig)
// {
//     static int bit = 0;
//     static unsigned int num = 0;
//     char *str = NULL;

//     if (sig == SIGUSR1)
//         num |= (1u << bit);
//     bit++;
//     if (bit == 32)
//     {
//         str = new_str(num);
//         g_state = 2; // Move to receiving message characters
//         bit = 0;
//         num = 0;
//         return (str);
//     }
//     return (str);
// }

// // *** ENGLISH ***
// // Handles message characters reception
// // *** ESPAÑOL ***
// // Maneja la recepción de los caracteres del mensaje
// // *** FRANÇAIS ***
// // Gère la réception des caractères du message
// char *ft_handler_char(int sig, char *str)
// {
//     static int bit = 0;
//     static int c = 0;
//     static int i = 0;

//     if (sig == SIGUSR1)
//         c |= (0x01 << bit); // Add bit to the current character
//     bit++;
//     if (bit == 8)
//     {
//         str[i++] = c;
//         if (c == '\0' || c == 255) // End of message or client disconnected
//         {
//             if (c != 255)
//                 ft_printf("%s\n", str);
//             free(str);
//             str = NULL;
//             g_state = 0; // Reset state
//             i = 0;
//         }
//         bit = 0;
//         c = 0;
//     }
//     return (str);
// }

// // *** ENGLISH ***
// // Handles signals received by the server
// // *** ESPAÑOL ***
// // Maneja las señales recibidas por el servidor
// // *** FRANÇAIS ***
// // Gère les signaux reçus par le serveur
// void ft_handler(int sig)
// {
//     static char *str;
//     static unsigned int c_pid = 0;
//     int pid;

//     if (g_state == 0)
//         c_pid = ft_client_pid(sig); // Get client PID
//     else if (g_state == 1)
//     {
//         str = ft_handler_size(sig); // Get message size
//         kill(c_pid, SIGUSR1);       // Acknowledge
//     }
//     else if (g_state == 2)
//     {
//         str = ft_handler_char(sig, str); // Get message characters
//         if (g_state == 0)
//         {
//             pid = getpid();
//             ft_printf(BLUE "%s" CYAN "%s" RESET "%d\n", "PID", " -> ", pid);
//             kill(c_pid, SIGUSR2); // Notify completion
//             c_pid = 0;
//         }
//         else
//             kill(c_pid, SIGUSR1); // Acknowledge
//     }
// }

// // *** ENGLISH ***
// // Main function of the server
// // *** ESPAÑOL ***
// // Función principal del servidor
// // *** FRANÇAIS ***
// // Fonction principale du serveur
// int main(int ac, char **av)
// {
//     int pid;

//     if (ac != 1 && av)
//         ft_error(1);
//     pid = getpid();
//     ft_printf(BLUE "%s" CYAN "%s" RESET "%d\n", "PID", " -> ", pid);
//     signal(SIGUSR1, ft_handler);
//     signal(SIGUSR2, ft_handler);
//     while (1)
//         pause(); // Wait for signals
//     return (0);
// }

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
		tem = num;
		num = 0;
		bit = 0;
		g_state = 1;
		return (tem);
	}
	usleep(100);
	return (num);
}

char	*ft_handler_len(int sig)
{
	static int			bit;
	static unsigned int	num;
	char				*str;

	str = NULL;
	if (sig == SIGUSR1)
		num |= (1u << bit);
	bit++;
	if (bit >= 32)
	{
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
	if (bit == 8)
	{
		str[i++] = c;
		if (c == '\0' || c == 255)
		{
			if (c != 255)
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
	int					pid;

	pid = getpid();
	if (g_state == 0)
		c_pid = ft_client_pid(sig);
	else if (g_state == 1)
	{
		str = ft_handler_len(sig);
		kill(c_pid, SIGUSR1);
	}
	else if (g_state == 2)
	{
		str = ft_handler_char(sig, str);
		if (g_state == 0)
		{
			kill(c_pid, SIGUSR2);
			c_pid = 0;
			ft_printf(BLUE "%s" CYAN "%s" RESET "%d\n", "PID", " -> ", pid);
		}
		else
			kill(c_pid, SIGUSR1);
	}
}
// void ft_exit(sig)
// {
// 	(void)sig;
// 	if (sig == SIGTERM)
// 		g_state = 5;
// }

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 1 && av)
		ft_error(1);
	pid = getpid();
	ft_printf(BLUE "%s" CYAN "%s" RESET "%d\n", "PID", " -> ", pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (g_state != 5)
		pause();
	return (0);
}

	// signal(SIGTERM, ft_exit);