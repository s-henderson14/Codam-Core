/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:34:40 by sean              #+#    #+#             */
/*   Updated: 2023/06/15 18:00:03 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>
#include "../../libft/include/libft.h"

void    param_count_error();

void    pid_error();

void    send_signal(int signal, int pid);

#endif

