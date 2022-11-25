/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:24:24 by sean              #+#    #+#             */
/*   Updated: 2022/11/25 09:57:19 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

int		ft_printf(const char *fmt, ...);

int		print_char(int c);

int		print_string(char *s);

int		print_nbr(int n);

int		print_unsigned_i(unsigned int n);

int	    print_hex_lower(unsigned long n);

int		print_hex_upper(unsigned long n);

int		print_pointer(void *n);

#endif
