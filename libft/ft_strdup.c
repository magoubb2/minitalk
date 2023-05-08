/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:03:12 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 16:10:07 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//save a copy of a string
//allocates sufficient memory for a copy of the string s1, does the copy, 
//and returns a pointer to it.  The pointer may subsequently be used as an 
//argument to the function free(3).

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*val;

	len = ft_strlen(src);
	val = malloc(len + 1);
	len = 0;
	if (!src)
		return (NULL);
	if (!val)
		return (NULL);
	while (src[len])
	{
		val[len] = src[len];
		len++;
	}
	val[len] = '\0';
	return (val);
}
