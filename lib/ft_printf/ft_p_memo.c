/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:13:24 by mabril            #+#    #+#             */
/*   Updated: 2024/03/25 17:02:50 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_memo(unsigned long num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (num > 15)
		count += ft_memo(num / 16);
	num = num % 16;
	write(1, &base[num], 1);
	count++;
	return (count);
}
