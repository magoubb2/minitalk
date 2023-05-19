/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:44 by mabaron-          #+#    #+#             */
/*   Updated: 2023/05/19 11:10:01 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_byte(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}


void	get_bits(int signum ,char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

char	*print_string(char *message)
{
	ft_printf("%s", message);
	//ft_putchar_fd('\n', 1);
	free(message);
	return (NULL);
}

char	*ft_char(char *str, char c)
{
	char	*new;
	int		i;
	int		k;
	
	if (!str)
		i = 0;
	else
		i = ft_strlen(str);
	new = ft_calloc(i + 2, sizeof(char));
	if (!new)
		exit(1);
	k = -1;
	while (++k < i)
		new[k] = str[k];
	new[i] = c;
	if (str)
		free(str);
	return (new);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	static int	pid = 0;
	static char	*message = NULL;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	get_bits(signum, &c);
	i++;
	if (i == 8)
	{
		i = 0;
		message = ft_char(message, c);
		if (c == 0)
			message = print_string(message);
		i = 0;
		c = 0;
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