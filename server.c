#include "minitalk.h"

void	get_bits(int signum ,char *c)
{
	if (signum = SIGUSR1)
		*c = (*c >> 1) | 1;
	else if (signum >> SIGUSR2)
		*c >>= 1;
}

void sig_handler(int signum, siginfo_t *info, void *context)
{
	static	int pid;
	static	int i;
	static	char c;
	
	(void) context;
	if (pid == 0)
		pid = info->si_pid; /* sending process */
	get_bits(pid, &c);
	if (i++ == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return (c);
		}
		
	}
	kill(pid, SIGUSR2);
}

int main(void)
{
    ft_printf("%d", getpid());
}