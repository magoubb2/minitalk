/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:30:57 by mabaron-          #+#    #+#             */
/*   Updated: 2023/03/16 12:00:14 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Alloue (avec malloc(3)) et retourne un tableau de chaînes de 
//caractères obtenu en séparant ’s’ à l’aide du caractère ’c’, 
//utilisé comme délimiteur. Le tableau doit être terminé par NULL.
//Le tableau de nouvelles chaînes de caractères résultant du découpage.
//NULL si l’allocation échoue.
//Return: Le tableau de nouvelles chaînes de caractèresrésultant du découpage.
//NULL si l’allocation échoue.

#include "libft.h"

static int	nb_words(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			word++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (word);
}

static int	w_len(const char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		index;
	char	**split;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (nb_words(s, c) + 1));
	if (split == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if ((((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))))
		{
			if (i == 0)
				split[index] = ft_substr(s, i, w_len(s, c, i));
			else
				split[index] = ft_substr(s, i, w_len(s, c, i + 1) + 1);
			index++;
		}
		i++;
	}
	split[index] = NULL;
	return (split);
}
