/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:50:13 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:08:28 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Libère la mémoire de l’élément passé en argument en
//utilisant la fonction ’del’ puis avec free(3). La
//mémoire de ’next’ ne doit pas être free.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
