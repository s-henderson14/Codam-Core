/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:31:40 by sean              #+#    #+#             */
/*   Updated: 2023/06/18 15:31:59 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

void send_signal(int process_ID, int signal)
{
    if (kill(process_ID, signal) == -1)
        ft_putstr_fd("Error: Sending failed.\n", STDERR_FILENO);
}