/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:41:47 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:34:22 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copy memory area
//The memcpy() function copies n bytes from memory area src to memory 
//area dst. If dst and src overlap, behavior is undefined. 
//Applications in which dst and src might overlap should use memmove(3) instead.
//Return value: The memcpy() function returns the original value of dst.

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	i = 0;
	char_dest = (char *)dst;
	char_src = (char *)src;
	if (!dst || !src)
		return (NULL);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dst);
}
