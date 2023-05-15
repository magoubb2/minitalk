/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:44 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/15 18:25:12 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void print_byte(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}
*/

void	get_bits(int signum ,char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}


void sig_handler(int signum, siginfo_t *info, void *context)
{
    static int pid = 0;
    static int i = 0;
    static char buffer[BUFFER_SIZE];
    
    (void) context;
    if (pid == 0)
        pid = info->si_pid; /* sending process */
    get_bits(signum, &buffer[i / 8]);
    i++;
    if (i % 8 == 0)
    {
        if (buffer[(i / 8) - 1] == '\0')
        {
            pid = 0;
            write(1, buffer, ft_strlen(buffer));
            ft_memset(buffer, 0, BUFFER_SIZE);
            i = 0;
        }
    }
}

int main(void)
{
	struct sigaction	sa;

    ft_printf("SERVER PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}