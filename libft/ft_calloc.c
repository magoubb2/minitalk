/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:31:27 by mabaron-          #+#    #+#             */
/*   Updated: 2022/11/13 15:14:57 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//memory allocation
//description: function contiguously allocates enough space for count objects.
//functions allocate memory.
//The allocated memory is aligned such that it can be used for any data type
//that are size bytes of memory each and returns a pointer to the 
//allocated memory.The allocated memory is filled with bytes of value zero.
//Return values: functions return a pointer to allocated memory.
//If there is an error, they return a NULL pointer and set errno to ENOMEM.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!count || !size)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / count < size)
		return (NULL);
	str = malloc(count * size);
	if (str == NULL)
		return (0);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
