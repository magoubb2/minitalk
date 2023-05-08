/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:39:03 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 13:26:48 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	i = 0;
	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
	{
		return (0);
	}
	while ((char_s1[i] != '\0' || char_s2[i] != '\0')
		&& (char_s1[i] == char_s2[i]) && (i < n - 1))
	{
		i++;
	}
	return (char_s1[i] - char_s2[i]);
}
