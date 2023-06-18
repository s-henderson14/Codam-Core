/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:34:40 by sean              #+#    #+#             */
/*   Updated: 2023/06/18 22:13:08 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/types.h>
#include "../libft/libft.h"


void    argc_error();

void    process_ID_error();

void    send_signal(pid_t process_ID, int signal);

void	send_string(pid_t process_ID, char* string);

void    handle_signal(int signal, siginfo_t *info, void *context);

#endif

