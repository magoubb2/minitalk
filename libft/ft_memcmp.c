/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:42:44 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:22:06 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compare byte string
//Description: compares byte string s1 against byte string s2.  
//Both strings are assumed to be n bytes long.
//Return Value: returns zero if the two strings are identical, 
//otherwise returns the difference between the first two differing bytes

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	i = 0;
	char_str1 = (unsigned char *)s1;
	char_str2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
	{
		return (0);
	}
	while ((char_str1[i] == char_str2[i]) && (i < n - 1))
	{
		i++;
	}
	return (char_str1[i] - char_str2[i]);
}
