/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:06:48 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/25 18:05:26 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_utils(unsigned int n, int *num)
{
	if (n > 9)
	{
		if (n < 16)
		{
			*num += ft_putchar_fd((n + 'W'), 1);
		}
		else
		{
			ft_puthex_utils((n / 16), num);
			ft_puthex_utils((n % 16), num);
		}
	}
	else
		*num += ft_putchar_fd((n + 48), 1);
}

size_t	ft_puthex(unsigned int n)
{
	int	num;

	num = 0;
	ft_puthex_utils(n, &num);
	return ((size_t)num);
}

static void	ft_puthex_uppercase_utils(unsigned int n, int *num)
{
	if (n > 9)
	{
		if (n < 16)
		{
			*num += ft_putchar_fd((n + 55), 1);
		}
		else
		{
			ft_puthex_uppercase_utils((n / 16), num);
			ft_puthex_uppercase_utils((n % 16), num);
		}
	}
	else
		*num += ft_putchar_fd((n + 48), 1);
}

size_t	ft_puthex_uppercase(unsigned int n)
{
	int	num;

	num = 0;
	ft_puthex_uppercase_utils(n, &num);
	return ((size_t)num);
}
