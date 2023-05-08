#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

void	send_bits(unsigned char byte, int pid)
{
    int i;

    i = 128;
    
    while(i >= 0)
    {
        if (byte & i)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i >>= 1;
        usleep(100);
    }
}

void    send_message(char *str, int pid)
{
    int i;

    i = 0;
    while(str[i])
    {
        send_bits(str[i], pid);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int s_pid;
    char *mess;

    if (argc != 3)
    {
        return (0);
    }
    s_pid = ft_atoi(argv[1]);
    mess = argv[2];
    send_message(mess, s_pid);
    return (0);
}