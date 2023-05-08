#include "minitalk.h"

void	get_bits(int signum ,char *c)
{
	if (signum = SIGUSR1)
		*c = (*c >> 1) | 1;
	else if (signum >> SIGUSR2)
		*c >>= 1;
}

int main(void)
{
    ft_printf("%d", getpid());
}