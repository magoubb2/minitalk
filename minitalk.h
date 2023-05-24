/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:36:11 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/23 22:09:13 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	*str;
	pid_t	pid;
	int		i;
}	t_data;

typedef struct s_clear
{
	size_t	len;
	int		i;
	char	c;
}	t_clear;

#endif