/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:17:42 by mabril            #+#    #+#             */
/*   Updated: 2024/03/25 17:00:30 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		count = count + 6;
		return (count);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}
