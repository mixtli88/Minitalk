/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:30:26 by mabril            #+#    #+#             */
/*   Updated: 2024/11/19 10:59:12 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// *** ENGLISH ***
// Sends `bits` number of bits of `num` to the server without requiring acknowledgment.
// *** ESPAÑOL ***
// Envía `bits` bits de `num` al servidor sin requerir confirmación.
// *** FRANÇAIS ***
// Envoie `bits` bits de `num` au serveur sans nécessiter d'accusé de réception.
void ft_send_bits_no_conf(int s_pid, unsigned int num, int bits)
{
    int bit = 0;

    while (bit < bits)
    {
        if ((num & (1 << bit)))
            kill(s_pid, SIGUSR1); // Send a 1 bit
        else
            kill(s_pid, SIGUSR2); // Send a 0 bit
        usleep(1000); // Small delay to ensure signal transmission
        bit++;
    }
}

// *** ENGLISH ***
// Prints an error message based on the error code and exits the program.
// *** ESPAÑOL ***
// Imprime un mensaje de error según el código de error y sale del programa.
// *** FRANÇAIS ***
// Affiche un message d'erreur basé sur le code d'erreur et quitte le programme.
void ft_error(int num)
{
    if (num == 1)
    {
        ft_printf(RED "🚫 *** error ***\n" RESET);
        ft_printf(YELLOW "Try: ./server\n" RESET); // Incorrect usage for server
    }
    else if (num == 2)
    {
        ft_printf(RED "🚫 *** error ***\n" RESET);
        ft_printf(YELLOW " 🚧 The message was broken 🚧\n" RESET); // Message transmission failed
    }
    else if (num == 3)
    {
        ft_printf("\033[91mError: wrong format.\033[0m\n");
        ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n"); // Incorrect usage for client
    }
    exit(1);
}

// *** ENGLISH ***
// Allocates memory for a new string of length `len + 1` and initializes it to zero.
// *** ESPAÑOL ***
// Reserva memoria para una nueva cadena de longitud `len + 1` y la inicializa a cero.
// *** FRANÇAIS ***
// Alloue de la mémoire pour une nouvelle chaîne de longueur `len + 1` et l'initialise à zéro.
char *new_str(int len)
{
    char *str;

    str = ft_calloc((len + 1), sizeof(char)); // Allocate memory for the string
    if (!str) // Check allocation failure
        exit(1);
    return (str);
}
