/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:39:24 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 18:15:05 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int	dg;

	dg = 0;
	if (n < 0)
		dg++;
	if (n == 0)
		dg++;
	while (n != 0)
	{
		n = n / 10;
		dg++;
	}
	return (dg);
}

char	*arr(long d, int uni)
{
	char	*str;

	str = malloc(sizeof(char) * uni + 1);
	if (!str)
		return (0);
	if (d == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (d < 0)
	{
		d = -d;
		str[0] = '-';
	}
	str[uni] = '\0';
	while (uni-- >= 0 && d != 0)
	{
		str[uni] = (d % 10) + '0';
		d = d / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		uni;
	long	i;

	i = n;
	uni = len(n);
	str = arr(i, uni);
	return (str);
}
