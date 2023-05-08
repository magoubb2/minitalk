/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:37:29 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:07:26 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Supprime et libère la mémoire de l’élément passé en
//paramètre, et de tous les éléments qui suivent, à
//l’aide de ’del’ et de free(3)
//Enfin, le pointeur initial doit être mis à NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	clear = *lst;
	while (clear)
	{
		next = clear->next;
		del(clear->content);
		free(clear);
		clear = next;
	}
	*lst = NULL;
}
