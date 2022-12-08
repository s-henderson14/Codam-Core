/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:39 by sean              #+#    #+#             */
/*   Updated: 2022/12/05 15:37:34 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

static int	printer(const char fmt, va_list *args)
{
	int	len;

	len = 0;
	if (fmt == 'c')
		return (print_char(va_arg(*args, int)));
	else if (fmt == 's')
		return (print_string(va_arg (*args, char *)));
	else if (fmt == 'p')
		return (print_pointer(va_arg(*args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (print_nbr(va_arg(*args, int)));
	else if (fmt == 'u')
		return (print_unsigned_i(va_arg(*args, unsigned int)));
	else if (fmt == 'x')
		return (print_hex_lower(va_arg(*args, unsigned int)));
	else if (fmt == 'X')
		return (print_hex_upper(va_arg(*args, unsigned int)));
	else if (fmt == '%')
		return (print_char('%'));
	return (len);
}

static int	fmt_index(const char *fmt, va_list *args)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{	
			if (print_char(*fmt) == -1)
				return (-1);
			count++;
		}
		else if (*fmt++ == '%')
		{	
			if (*fmt == '\0')
				return (count);
			temp = printer(*fmt, args);
			count += temp;
		}
		fmt++;
	}	
	return (count);
}

int	ft_printf(const char *fmt, ...)
{	
	int		len;
	va_list	args;

	va_start(args, fmt);
	len = fmt_index(fmt, &args);
	if (len == -1)
		return (-1);
	va_end(args);
	return (len);
}

/*int	main(void)
{
	char	*string;

	
	string = "hello % go";
	printf("%s\n", string);
	ft_printf("%s\n", string);
	ft_printf("%%\n");
	ft_printf("%%\n%") ;
}*/