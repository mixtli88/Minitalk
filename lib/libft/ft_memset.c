/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:57:58 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 18:26:56 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tem;

	tem = (unsigned char *)b;
	while (len > 0)
	{
		(*tem) = (unsigned char )c;
		tem++;
		len--;
	}
	return (b);
}
