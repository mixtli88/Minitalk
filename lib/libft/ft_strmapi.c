/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:08:09 by mabril            #+#    #+#             */
/*   Updated: 2024/03/15 18:25:56 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	size_t			len;

	len = ft_strlen(s) + 1;
	i = 0;
	res = malloc(sizeof(char) * (len));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i ++;
	}
	res[i] = '\0';
	return (res);
}
