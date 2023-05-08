/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:49:34 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/25 18:06:28 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(fd, s, ft_strlen(s)));
}
