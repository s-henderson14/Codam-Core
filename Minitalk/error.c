#include "../../include/minitalk.h"

void    param_count_error()
{
    ft_putstr_fd("Error: not enough parameters were provided. Example: './client <server_pid> <signal>'", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void    pid_error()
{
    ft_putstr_fd("Error: no such PID exists", STDERR_FILENO);
    exit(EXIT_FAILURE);
}