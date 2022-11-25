/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:39 by sean              #+#    #+#             */
/*   Updated: 2022/11/25 09:58:27 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

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
			return (len += print_hex_lower(va_arg(*args, unsigned long)));
		else if (fmt == 'X')
			return (len += print_hex_upper(va_arg(*args, unsigned long)));
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
	//printf(" NULL %s NULL ", NULL);
	ft_printf(" NULL %s NULL ", NULL);
	
	void *ptr;
	
	ptr = NULL;
	ft_printf("Print the character %c.\n", 'H');
	ft_printf("If you could do a %s, I'd be impressed.\n", "word");
	ft_printf("But if you got me a number %d,\
	 now that would be something!\n", 5);
	ft_printf("So you really want to print a pointer? %p, woah you did!\n", (void *)&ptr);
	printf("So you really want to print a pointer? %p, woah you did!\n", (void *)&ptr);
	ft_printf("Hexa lower %x yuss!", 3317);
	ft_printf("Hexa upper %X yuss!", 3317);

}*/
