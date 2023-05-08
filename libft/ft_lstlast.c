/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:43:05 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:10:35 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Renvoie le dernier élément de la liste.

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (lst == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
