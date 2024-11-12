/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:31:43 by mabril            #+#    #+#             */
/*   Updated: 2024/03/25 17:00:24 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnrb(int i)
{
	long	nb;
	int		count;

	nb = i;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	if (nb > 9)
		count += ft_putnrb((nb / 10));
	nb = (nb % 10) + '0';
	write(1, &nb, 1);
	count++;
	return (count);
}

// int	main(void)
// {
// 	int	n;
// 	int	p;

// 	n = -10;
// 	p = 0;
// 	ft_putnrb(n, p);
// }
