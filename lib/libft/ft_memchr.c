/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:05:16 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 18:15:41 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cptr;
	unsigned char	cch;

	cptr = (unsigned char *)s;
	cch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cptr[i] == cch)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
