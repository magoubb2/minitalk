/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:18:12 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/25 18:06:18 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	ssize_t			i;

	i = 0;
	if (n < 0)
	{
		nbr = -n;
		i += write(fd, "-", 1);
	}
	else
	{
		nbr = n;
	}
	if (n / 10 != 0)
		i += ft_putnbr_fd(nbr / 10, fd);
	i += ft_putchar_fd(nbr % 10 + '0', fd);
	return (i);
}
