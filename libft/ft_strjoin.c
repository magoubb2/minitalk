/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:47:43 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 16:32:43 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Alloue (avec malloc(3)) et retourne une nouvelle
//chaîne, résultat de la concaténation de s1 et s2.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;

	if (s1 == NULL || s2 == NULL)
		return (0);
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (nstr == NULL)
		return (0);
	ft_strlcpy(nstr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(nstr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (nstr);
}
