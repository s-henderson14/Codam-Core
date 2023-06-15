#include "../../include/minitalk.h"

int	on = 0;

void send_signal(int server_pid, int signal)
{
    if (kill(server_pid, signal) == -1)
    {
        ft_putstr_fd("Error: Sending failed.", STDERR_FILENO);
    }
}

static void	send_string(int pid, char *str)
{
	int	i;
	int	bit;
	int	bit_max = 8;

	while (str[i])
	{	
		bit = 0;
		while(bit < bit_max)
		{
			if (str[i] >> bit & 1 == 1)
				send_signal(pid, SIGUSR2);
			else if (str[i] >> bit & 1 == 0)
				send_signal(pid, SIGUSR1);
			bit++;
			while(!on)
				pause();
			on = 0;
		}
		i++;
	}
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		on = 1;
}

int main(int argc, char **argv)
{
    int	pid;

	signal(SIGUSR1, signal_handler);
	if (argc != 3)
		param_count_error();
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1 || pid < 1)
		pid_error();
	send_string(pid, argv[2]);
	return (0);
}