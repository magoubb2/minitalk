/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:29:58 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:46:21 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Écrit La chaîne de caractères ’s’ sur le
//descripteur de fichier donné suivie d’un retour à la ligne.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	else
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
