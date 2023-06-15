#include "../../include/minitalk.h"

int main()
{
    const char          *pid = ft_itoa(getpid());
    
    ft_putstr_fd("Server PID:", STDOUT_FILENO);
    ft_putstr_fd((char*) pid, STDOUT_FILENO);
    ft_putstr_fd("\n", STDOUT_FILENO);
    sigaction()
    

}