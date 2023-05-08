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