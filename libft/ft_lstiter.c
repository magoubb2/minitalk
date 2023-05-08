/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:01:44 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:15:52 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu 
//chaque élément.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
