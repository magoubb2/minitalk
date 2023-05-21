/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:34 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/20 19:38:41 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include <stdlib.h>

/*
void print_byte(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}
*/

t_data g_data;

void	send_bits(char byte, int pid)
{
	if ((byte) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 1;

	(void) info;
	(void) context;
 	if (signum == SIGUSR1)
	{
		send_bits(g_data.str[0] >> i++, g_data.pid);
		if (i == 8)
		{
			i = 0;
			g_data.str++;
		}
	}
	else
	{
		write(1, "The end\n", 8);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	struct sigaction	sa;
    int					s_pid;
	int					byte_idx;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
    s_pid = ft_atoi(argv[1]);
	byte_idx = 0;
    if (argc != 3)
    {
		ft_printf("WRONG NUMBER OF ARGUMENTS");
       return (0);
	}
	g_data.str = argv[2];
	g_data.pid = s_pid;
	if (sigaction(SIGUSR1, &sa, NULL) == 1)
		ft_printf("%s" "error_1");
	if (sigaction(SIGUSR2, &sa, NULL) ==  1)
		ft_printf("%s" "error_2");
	send_bits(argv[2][0], s_pid);
	while (1)
		pause();
    return (0);
}