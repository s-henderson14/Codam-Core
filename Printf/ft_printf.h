/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:14:18 by shenders          #+#    #+#             */
/*   Updated: 2022/11/25 12:57:59 by shenders         ###   ########.fr       */
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

int		print_hex_lower(unsigned int n);

int		print_hex_upper(unsigned int n);

int		print_pointer(void *add);

#endif
