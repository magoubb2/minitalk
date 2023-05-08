/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:31:49 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 13:32:34 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*nstr;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr((char *)set, s1[start]))
		start++;
	while (end > start && ft_strchr((char *)set, s1[end - 1]))
		end--;
	nstr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		nstr[i++] = s1[start++];
	}
	nstr[i] = 0;
	return (nstr);
}
