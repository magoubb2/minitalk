/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:36:11 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/20 18:47:05 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"


typedef struct s_data
{
	char	*str;
	pid_t	pid;
}	t_data;

int		ft_atoi(const char *str);
char	*straddc(char *str, char c);

#endif