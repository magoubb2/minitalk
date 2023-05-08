/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:08:55 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:14:23 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convert ASCII string to integer
//description: Converts the initial portion of the string pointed to by str 
//to int representation.

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	res;
	int	i;

	n = 1;
	res = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && ft_strchr(WHITE_SPACE, str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (n * res);
}
