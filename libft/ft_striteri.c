/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:35:44 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 16:12:09 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Applique la fonction ’f’ à chaque caractère de la
//chaîne de caractères transmise comme argument,
//et en passant son index comme premier argument.
//Chaque caractère est transmis par adresse à ’f’
//afin d’être modifié si nécessaire.

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
