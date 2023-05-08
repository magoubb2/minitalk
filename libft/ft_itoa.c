/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:06:10 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:40:00 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Alloue (avec malloc(3)) et retourne une chaîne
//de caractères représentant l’entier ’n’ reçu en
//argument. Les nombres négatifs doivent être gérés.
//retourne: La chaîne de caractères représentant l’entier. 
//NULL si l’allocation échoue.

#include "libft.h"

int static	nbnb(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = (nb / 10);
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = nbnb(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		if (str[0] == '-' && n < 0)
			str[i--] = '0' - (n % 10);
		else
			str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
