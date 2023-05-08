/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:20:20 by mabaron-          #+#    #+#             */
/*   Updated: 2023/01/06 14:35:00 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
