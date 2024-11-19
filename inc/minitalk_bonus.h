/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:07:21 by mabril            #+#    #+#             */
/*   Updated: 2024/11/18 18:20:12 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

void	ft_error(int num);
char	*new_str(int len);
void	ft_send_bits_no_conf(int s_pid, unsigned int num, int bits);

#endif