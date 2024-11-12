/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:46:21 by mabril            #+#    #+#             */
/*   Updated: 2024/04/29 11:42:23 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putstr(char *c);
int	ft_putchar(char c);
int	ft_puthexatit(unsigned int num);
int	ft_unsigne(unsigned int i);
int	ft_putnrb(int i);
int	ft_puthexaup(unsigned int num);
int	ft_memo(unsigned long num);
int	ft_printf(const char *str, ...);
#endif