/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:48:32 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:38:25 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copy byte string
//copies len bytes from string src to string dst.  The two strings may overlap
//; the copy is always done in a non-destructive manner.
//Return: returns the original value of dst.

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	long long	i;
	char		*char_str1;
	char		*char_str2;

	i = len - 1;
	char_str1 = (char *)dst;
	char_str2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	else
	{
		while (i != -1ll)
		{
			char_str1[i] = char_str2[i];
			i--;
		}
	}
	return (dst);
}
