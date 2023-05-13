/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:36:11 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/11 10:36:13 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"


typedef struct s_data
{
    unsigned char	received_byte;
    int				bit_count;
}			t_data;

int ft_atoi(const char *str);

#endif