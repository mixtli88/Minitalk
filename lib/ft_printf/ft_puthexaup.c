/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:13:24 by mabril            #+#    #+#             */
/*   Updated: 2024/03/25 17:00:14 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexaup(unsigned int num)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (num > 15)
		count += ft_puthexaup(num / 16);
	num = num % 16;
	write(1, &base[num], 1);
	count++;
	return (count);
}

// int	main(void)
// {
// 	int	t;
// 	int	count;

// 	t = 3456;
// 	count = 0;
// 	ft_puthexaup(t, count);
// 	return (0);
// }
