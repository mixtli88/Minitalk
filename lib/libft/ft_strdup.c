/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:36:36 by mabril            #+#    #+#             */
/*   Updated: 2024/04/01 18:05:37 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copie;
	int		i;

	len = 0;
	i = 1;
	while (s1[len])
		len++;
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (0);
	while (s1[i - 1])
	{
		copie[i - 1] = s1[i - 1];
		i++;
	}
	copie[i - 1] = '\0';
	return (copie);
}
