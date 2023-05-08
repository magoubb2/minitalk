/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:18:21 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:14:00 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Alloue (avec malloc(3)) et renvoie un nouvel élément. La variable membre 
//’content’ est initialisée à l’aide de la valeur du paramètre’ content’.
//La variable ’next’ est initialisée à NULL.

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}
