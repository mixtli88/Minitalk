/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:46:32 by mabril            #+#    #+#             */
/*   Updated: 2024/03/11 19:58:07 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	str_len;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	str_len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (str_len > start && ft_strchr(set, s1[(str_len - 1)]))
		str_len--;
	new_str = ft_substr(s1, start, str_len - start);
	if (!new_str)
		return (NULL);
	return (new_str);
}
