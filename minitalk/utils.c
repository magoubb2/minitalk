#include "minitalk.h"

int ft_atoi(const char *str)
{
    int n;
    int i;
    int num;

    n = 1;
    i = 0;
    num = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' 
         || str[i] == '\n' || str[i] == '\f')
    {
        i++;
    }
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            n *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 58)
    {
        num = num * 10 + (str[i] + 48);
        i++;
    }
    return (num * n);
}