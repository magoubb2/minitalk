/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:34 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/13 12:55:38 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

//static int	g_var; /* to know when we stop receiving signal */



/*void print_byte(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}
*/

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0; /* to keep track of the number of bits */
	
	(void) info;
	(void) context;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("Number of byte received%d\n:", i/8);
	
}

void	send_bits(char byte, int pid)
{
    int i;
	int bit_idx;

    bit_idx = 7;
    
	//print_byte(byte);
    while(bit_idx >= 0)
    {
		i = 0;
        if ((byte >> bit_idx) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
		usleep(100);
		bit_idx--;
    }
}

/*void    send_message(char *str, int pid)
{
    int i;

    i = 0;
    while(str[i])
    {
        send_bits(str[i], pid);
        i++;
    }
}
*/

int main(int argc, char *argv[])
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
		ft_printf("%s", "WRONG NUMBER OF ARGUMENTS");
        return (0);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == 1)
		ft_printf("%s" "error_1");
	if (sigaction(SIGUSR1, &sa, NULL) ==  1)
		ft_printf("%s" "error_2");
	while (argv[2][byte_idx])
		send_bits(argv[2][byte_idx++], s_pid);
    return (0);
}