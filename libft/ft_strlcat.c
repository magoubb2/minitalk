/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:29:22 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 18:17:34 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (dst[i] != '\0' && i < dstsize)
	{
		i++;
	}
	while ((src[index]) && ((index + i + 1) < dstsize))
	{
		dst[i + index] = src[index];
		index++;
	}
	if (i != dstsize)
		dst[i + index] = '\0';
	return (i + ft_strlen(src));
}
