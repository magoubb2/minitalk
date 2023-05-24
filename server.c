/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:44 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/23 19:54:05 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "minitalk.h"

t_data	g_data;

int	ft_clear(t_clear *data)
{
	data->len = 0;
	data->i = 0;
	data->c = 0;
	return (0);
	if (g_data.str)
		free(g_data.str);
	g_data.str = NULL;
	return (0);
}

char	*print_string(char *message, bool print, t_clear *data)
{
	if (print)
		ft_printf("%s", message);
	ft_clear(data);
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
		if (!new)
			new = NULL;
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
	static t_clear data = {0, 0, 0};

	if (!g_data.pid)
		g_data.pid = info->si_pid;
	if (info->si_pid != g_data.pid && info->si_pid)
	{
		g_data.str = print_string(g_data.str, 0, &data);
		g_data.pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		data.c = data.c | (1 << data.i);
	++data.i;
	if (data.i == 8)
	{
		g_data.str = ft_char(g_data.str, data.c, data.len++);
		data.i = 0;
		if (data.c == '\0')
		{
			g_data.str = print_string(g_data.str, 1, &data);
			kill(g_data.pid, SIGUSR2);
			return ;
		}
		data.c = 0;
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