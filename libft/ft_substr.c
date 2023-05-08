/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:45:21 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/02 13:51:26 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*nstr;

	i = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	nstr = malloc(sizeof(char) * len + 1);
	if (nstr == NULL)
		return (0);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	ft_strlcpy(nstr, s + start, len + 1);
	return (nstr);
}
