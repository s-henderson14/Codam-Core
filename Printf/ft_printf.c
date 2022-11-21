/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:39 by sean              #+#    #+#             */
/*   Updated: 2022/11/21 18:38:26 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

static void	printer(const char *fmt, va_list args)
{
	if (*fmt == 'c')
		print_char(va_arg(args, int));
	else if (*fmt == 's')
		print_string(va_arg (args, char *));
	else if (*fmt == 'd' || *fmt == 'i')
		print_nbr(va_arg(args, int));
	else if (*fmt == 'p')
	{
		write(1, "0x", 3);
		print_hex(va_arg(args, int));
	}
}	

int	ft_printf(const char *fmt, ...)
{	
	va_list	args;

	va_start(args, fmt);
	while (*fmt)
	{	
		if (*fmt != '%')
			print_char(*fmt);
		else if (*fmt == '%')
		{	
			fmt++;
			printer(fmt, args);
		}
		fmt++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	void *ptr;
	
	ptr = NULL;
	ft_printf("Print the character %c.\n", 'H');
	ft_printf("If you could do a %s, I'd be impressed.\n", "word");
	ft_printf("But if you got me a number %d,\
	 now that would be something!\n", 5);
	ft_printf("So you really want to print a pointer? %p, woah you did!\n", (void *)&ptr);
	printf("So you really want to print a pointer? %p, woah you did!\n", (void *)&ptr);
}
