/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:44 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/20 20:05:28 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "minitalk.h"

/*void print_byte(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}
*/

t_data	g_data;

// void	get_bits(int signum ,char *c)
// {
// 	if (signum == SIGUSR1)
// 		*c = (*c << 1) | 1;
// 	else if (signum == SIGUSR2)
// 		*c <<= 1;
// }

char	*print_string(char *message, bool print)
{
	if (print)
		ft_printf("%s", message);
	//ft_putchar_fd('\n', 1);
	free(message);
	return (NULL);
}

char	*ft_char(char *str, char c, size_t len)
{
	static size_t	size = 128;
	char*			new;
	
	if (!str)
		new = malloc(size);
	else if (len >= size)
	{
		size *= 2;
		new = malloc(size);
		ft_strlcpy(new, str, len + 1);
		free(str);
	}
	else
		new = str;
	new[len] = c;
	return (new);
}


void	sig_handler(int signum, siginfo_t *info)
{
	static size_t	len = 0;
	static int		i = 0;
	static char		c = 0;

	if (info->si_pid)
		g_data.pid = info->si_pid;
	if (signum == SIGUSR1)
		c = c | (1 << i);
	++i;
	if (i == 8)
	{
		g_data.str = ft_char(g_data.str, c, len++);
		i = 0;
		if (c == '\0')
		{
			write(1, g_data.str, len);
			len = 0;
			c = 0;
			kill(g_data.pid, SIGUSR2);
			return ;
		}
		c = 0;
	}
	kill(g_data.pid, SIGUSR1);
}


int main(void)
{
	struct sigaction	sa;

    ft_printf("SERVER PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = (void (*)(int, siginfo_t*, void*))sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_data.str = 0;
	while (1)
		pause();
}