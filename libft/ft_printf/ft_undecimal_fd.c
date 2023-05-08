/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undecimal_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:13:19 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/25 18:20:27 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_undecimal_fd(unsigned int n, int fd)
{
	size_t	i;

	i = 0;
	if (n < 10)
	{
		return (ft_putchar_fd(n + '0', fd));
	}
	else
		i += ft_undecimal_fd(n / 10, fd);
	i += ft_undecimal_fd(n % 10, fd);
	return (i);
}
