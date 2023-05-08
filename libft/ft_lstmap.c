/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:17:16 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:16:06 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Itère sur la liste ’lst’ et applique la fonction’f ’au contenu de 
//chaque élément. 
//Crée une nouvelle liste résultant des applications successives de’f’. 
//La fonction ’del’ est là pour détruire le contenu d’un élément si nécessaire.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
			ft_lstclear(&temp, del);
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
