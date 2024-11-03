/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:11:39 by mike              #+#    #+#             */
/*   Updated: 2024/03/15 18:17:25 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (dest == src || !len)
		return (dest);
	if (src < dest)
	{
		i = len;
		while (i > 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i++, i <= len)
			cdest[i - 1] = csrc[i - 1];
	}
	return (dest);
}
