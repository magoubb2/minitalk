/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:43:05 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:14:34 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//write zeroes to a byte string
//description: Writes n zeroed bytes to the string s.  If n is zero, 
//bzero() does nothing.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
