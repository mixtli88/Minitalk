/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:41:30 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 18:25:04 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	cp = malloc((len + 1) *(sizeof(char)));
	if (!cp)
		return (0);
	while (len > 0)
	{
		cp[i] = s[start + i];
		i++;
		len--;
	}
	cp[i] = '\0';
	return (cp);
}
