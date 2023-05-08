/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:21:42 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:20:08 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locate byte in byte string.
//Description:
//locates the first occurrence of c (converted to an unsigned char) 
//in string s.
//Return Value: The memchr() function returns a pointer to the byte located, 
//or NULL if no such byte exists within n bytes.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return (((void *)s) + i);
		}
		i++;
	}
	return (NULL);
}
