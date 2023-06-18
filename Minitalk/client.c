/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:17:46 by sean              #+#    #+#             */
/*   Updated: 2023/06/18 22:29:16 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

int	receiving = 0;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		receiving = 1;
}


void	send_string(int process_ID, char* string)
{
	int	bits_shifted;
	int	i;
	
	i = 0;
	bits_shifted = 7;
	while(string[i])
	{	
		bits_shifted = 7;
		while(bits_shifted >= 0)
		{
			if (string[i] >> bits_shifted & 1) // If first bit of char is a 1.
				send_signal(process_ID, SIGUSR2);
			else
				send_signal(process_ID, SIGUSR1); // If first bit of char is a 0.
			bits_shifted--;
			while(!receiving)
				;
			receiving = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
    pid_t	process_ID;

	signal(SIGUSR1, signal_handler);
	if (argc != 3)
		argc_error();
	process_ID = ft_atoi(argv[1]);
	if (kill(process_ID, 0) == -1 || process_ID < 1) //Check if PID exists or call for PID has failed. If server is not listening, process will have ended.
		process_ID_error();
	write(1, "\n", 1);
	send_string(process_ID, argv[2]);
	return (0);
}

// static void	send_string(int pid, char *str)
// {
// 	int	i;
// 	int	bit;
// 	int	bit_max = 8;

// 	while (str[i])
// 	{	
// 		bit = 0;
// 		while(bit < bit_max)
// 		{
// 			if (str[i] >> bit & 1 == 1)
// 				send_signal(pid, SIGUSR2);
// 			else if (str[i] >> bit & 1 == 0)
// 				send_signal(pid, SIGUSR1);
// 			bit++;
// 			while(!on)
// 				pause();
// 			on = 0;
// 		}
// 		i++;
// 	}
// }