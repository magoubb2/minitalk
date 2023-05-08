/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:34:50 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/25 18:03:43 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list args, const char form)
{
	{
		if (form == 'c')
			return (ft_putchar_fd(va_arg(args, int), 1));
		else if (form == 's')
			return (ft_putstr_fd(va_arg(args, char *), 1));
		else if (form == 'd' || form == 'i')
			return (ft_putnbr_fd(va_arg(args, int), 1));
		else if (form == 'u')
			return (ft_undecimal_fd(va_arg(args, int), 1));
		else if (form == 'x')
			return (ft_puthex(va_arg(args, unsigned int)));
		else if (form == 'X')
			return (ft_puthex_uppercase(va_arg(args, unsigned int)));
		else if (form == 'p')
			return (ft_putpointer(va_arg(args, void *)));
		else if (form == '%')
			return (ft_putchar_fd('%', 1));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_conversion(args, str[i + 1]);
			i++;
		}
		else
			print += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (print);
}
