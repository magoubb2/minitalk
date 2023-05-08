/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:47:55 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:56:28 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locate character in string
//locates the first occurrence of c (converted to a char) in the string pointed 
//to by s. The terminating null character is considered to be part of the 
//string ;therefore if c is `\0', the functions locate the terminating `\0'.
//Returns: return a pointer to the located character, or NULL if the character
//does not appear in the string.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
