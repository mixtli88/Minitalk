/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/18 20:36:41 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// *** ENGLISH ***
// Global variable to track received signals
// *** ESPAÑOL ***
// Variable global para rastrear señales recibidas
// *** FRANÇAIS ***
// Variable globale pour suivre les signaux reçus
static int g_received = 0;

// *** ENGLISH ***
// Signal handler for client-side communication acknowledgment
// *** ESPAÑOL ***
// Manejador de señales para reconocimiento de comunicación del cliente
// *** FRANÇAIS ***
// Gestionnaire de signaux pour l'accusé de réception côté client
void confirm_handle(int sig)
{
    if (sig == SIGUSR1)
        g_received = 1;  // Acknowledgment received
    else if (sig == SIGUSR2)
        g_received = 3;  // Communication error or termination signal
}

// *** ENGLISH ***
// Sends `bits` number of bits of the number `num` to the server
// *** ESPAÑOL ***
// Envía `bits` bits del número `num` al servidor
// *** FRANÇAIS ***
// Envoie `bits` bits du nombre `num` au serveur
void ft_send_bits(int s_pid, unsigned int num, int bits)
{
    int i = 0;
    int time_whait = 0;

    while (i < bits)
    {
        if (g_received == 3) // Error or disconnection signal
            break;
        g_received = 0;  // Reset acknowledgment
        if ((num & (1 << i)))
            kill(s_pid, SIGUSR1); // Send a 1 bit
        else
            kill(s_pid, SIGUSR2); // Send a 0 bit
        while (!g_received) // Wait for acknowledgment
        {
            usleep(1000);
            time_whait += 100;
            if (time_whait >= 500000) // Timeout (500ms)
                ft_error(2);
        }
        i++;
    }
}

// *** ENGLISH ***
// Sends a string `str` to the server
// *** ESPAÑOL ***
// Envía una cadena `str` al servidor
// *** FRANÇAIS ***
// Envoie une chaîne `str` au serveur
void ft_send_str(int s_pid, char *str, int len)
{
    int i = 0;

    while (i < len)
    {
        ft_send_bits(s_pid, str[i], 8); // Send each character (8 bits)
        i++;
    }
    ft_send_bits(s_pid, '\0', 8); // Send null terminator
}

// *** ENGLISH ***
// Handles Ctrl+C to send termination signal to server
// *** ESPAÑOL ***
// Maneja Ctrl+C para enviar una señal de terminación al servidor
// *** FRANÇAIS ***
// Gère Ctrl+C pour envoyer un signal de terminaison au serveur
void handle_sigint(int sig)
{
    static int s_pid;

    if (sig == g_received)
        s_pid = sig; // Save the server PID
    if (sig == SIGINT)
    {
        ft_send_bits(s_pid, 65535, 32); // Send disconnection signal (14 bits of 1)
        ft_error(2);
        exit(1);
    }
}

// *** ENGLISH ***
// Main function to send a message from the client to the server
// *** ESPAÑOL ***
// Función principal para enviar un mensaje del cliente al servidor
// *** FRANÇAIS ***
// Fonction principale pour envoyer un message du client au serveur
int main(int ac, char **av)
{
    int server_pid;
    int len;
    int client_pid;

    if (ac != 3)
        ft_error(3); // Invalid arguments
    server_pid = ft_atoi(av[1]); // Get server PID
    client_pid = getpid();       // Get client PID
    len = ft_strlen(av[2]);      // Get message length
    g_received = server_pid;     // Save server PID temporarily
    handle_sigint(server_pid);
    g_received = 0;
    signal(SIGUSR1, confirm_handle); // Set signal handlers
    signal(SIGUSR2, confirm_handle);
    signal(SIGINT, handle_sigint);
    ft_send_bits_no_conf(server_pid, client_pid, 32); // Send client PID
    ft_send_bits(server_pid, len, 32);               // Send message length
    ft_send_str(server_pid, av[2], len);             // Send message content
    return (0);
}
