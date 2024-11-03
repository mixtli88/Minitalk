/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:56:28 by mabril            #+#    #+#             */
/*   Updated: 2024/08/07 21:38:03 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!*s1 || !*s2 || n <= 0)
// 		return (2);
// 	while ((s1[i] != s2[i] && n > 0 || s1[i] == '\0'))
// 	{
// 		i++;
// 		--n;
// 	}
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!*s1 || !*s2 || n <= 0)
		return (2);
	while ((s1[i] == s2[i] && n > i && s1[i] != '\0'))
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
