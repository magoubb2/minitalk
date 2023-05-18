/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:45:21 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/14 14:08:44 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;

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
