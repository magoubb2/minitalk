/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:56:38 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/25 18:04:59 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlen(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != '\0')
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_puthex_ptr(unsigned long long n)
{
	if (n > 9)
	{
		if (n < 16)
		{
			ft_putchar_fd((n + 'W'), 1);
		}
		else
		{
			ft_puthex_ptr(n / 16);
			ft_puthex_ptr(n % 16);
		}
	}
	else
		ft_putchar_fd((n + 48), 1);
}

size_t	ft_putpointer(void *ptr)
{
	unsigned int	putlen;

	putlen = 0;
	putlen += write(1, "0x", 2);
	if (ptr == 0)
		putlen += write(1, "0", 1);
	else
	{
		ft_puthex_ptr((unsigned long long)ptr);
		putlen += ft_putlen((unsigned long long)ptr);
	}
	return (putlen);
}
