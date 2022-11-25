/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:39 by sean              #+#    #+#             */
/*   Updated: 2022/11/25 15:25:46 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <ctype.h>

static int	printer(const char fmt, va_list *args)
{
	int	len;

	len = 0;
	while (fmt)
	{
		if (fmt == 'c')
			return (len += print_char(va_arg(*args, int)));
		else if (fmt == 's')
			return (len += print_string(va_arg (*args, char *)));
		else if (fmt == 'p')
			return (len += print_pointer(va_arg(*args, void *)));
		else if (fmt == 'd' || fmt == 'i')
			return (len += print_nbr(va_arg(*args, int)));
		else if (fmt == 'u')
			return (len += print_unsigned_i(va_arg(*args, unsigned int)));
		else if (fmt == 'x')
			return (len += print_hex_lower(va_arg(*args, unsigned int)));
		else if (fmt == 'X')
			return (len += print_hex_upper(va_arg(*args, unsigned int)));
		else if (fmt == '%')
			return (len += print_char('%'));
	}
	return (0);
}	

int	ft_printf(const char *fmt, ...)
{	
	int		count;
	va_list	*pargs;
	va_list	args;

	count = 0;
	pargs = &args;
	va_start(args, fmt);
	if (*fmt < 0)
		return (-1);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			print_char(*fmt);
			count++;
		}
		else if (*fmt == '%')
		{
			fmt++;
			count += printer(*fmt, pargs);
		}
		fmt++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int	*ptr;
	
	ptr = NULL;
	ft_printf(" %p ", ptr);
	ft_printf(" %p ", 1);
	ft_printf(" %p ", 15);
	ft_printf(" %p ", 16);
	ft_printf(" %p ", 17);

	printf(" %p ", ptr);
	printf(" %p ", 1);
	printf(" %p ", 15);
	printf(" %p ", 16);
	printf(" %p ", 17);
}*/
