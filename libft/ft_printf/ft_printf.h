/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:35:33 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/29 15:01:20 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *src, ...);
size_t	ft_undecimal_fd(unsigned int n, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putchar_fd(char c, int fd);
size_t	ft_puthex(unsigned int n);
size_t	ft_puthex_uppercase(unsigned int n);
size_t	ft_strlen(const char *s);
size_t	ft_putpointer(void *ptr);

#endif