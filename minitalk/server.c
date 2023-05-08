#include "minitalk.h"

void handle_signal(int sig)
{
    unsigned char r_byte;
    int b_count;

    r_byte = 0;
    b_count = 0;
    if (sig == SIGUSR1)
    {
        r_byte |= 1 << b_count;
    }
    b_count++;
    if (b_count == 8)
    {
        printf("Received byte: %d\n", r_byte); // changer pour mon printf
        r_byte = 0;
        b_count = 0;
    }
}

int main(void)
{
    
    printf("%d", getpid());
}