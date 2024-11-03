/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:59:57 by mabril            #+#    #+#             */
/*   Updated: 2024/07/31 19:02:17 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*c1;
	char	*c2;

	c1 = (char *)haystack;
	c2 = (char *)needle;
	i = 0;
	if (c2[i] == '\0')
		return (c1);
	while (c1[i] && i < len)
	{
		j = 0;
		while (c1[i + j] == c2[j] && c1[i + j] && i + j < len)
		{
			j++;
			if (c2[j] == 0)
				return (c1 + i);
		}
		i++;
	}
	return (0);
}
