/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:43 by mabril            #+#    #+#             */
/*   Updated: 2024/05/03 11:23:36 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recurs(char c, va_list arg)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnrb(va_arg(arg, int));
	else if (c == 'u')
		count += ft_unsigne(va_arg(arg, unsigned int));
	else if (c == 'x')
		count += ft_puthexatit(va_arg(arg, unsigned int));
	else if (c == 'X')
		count += ft_puthexaup(va_arg(arg, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_memo(va_arg(arg, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			count += recurs(str[++i], arg);
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

// int	main(void)
// {
// 	void	*ptr;
// 	ptr = NULL;

// 	// ft_printf("\nAVEC LE VRAI PRINTF\n");
// 	ft_printf("%%%h$$ooo%5\n");
// 	printf("%%%ht$$ooo%5\n");

// 	// printf("AVEC MON FT_PRINTF\n\n");
// 	// printf("\n%i\n\n", ft_printf("%p", ""));
// 	return (0);
// // }