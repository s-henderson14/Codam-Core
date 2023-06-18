#include "../../include/minitalk.h"

void   argc_error()
{
    ft_putstr_fd("Error: not enough parameters were provided. Example: './client <server_pid> <signal>'\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void    process_ID_error()
{
    ft_putstr_fd("Error: no such PID exists\n", STDERR_FILENO);
    exit(EXIT_FAILURE);
}