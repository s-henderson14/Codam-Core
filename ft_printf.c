/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 13:09:03 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/18 15:36:28 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "printf.h"
#include <unistd.h>


// State:
// 0 : regular
// 1 : escape


void	printer(const char *placeholder, va_list args)
{
	int	mode;

	mode = 0;
	while (*placeholder)
	{	
		if (mode == 0)
		{	
			if (*placeholder == '%')
				mode = 1;
			else
				write(1, &*placeholder, 1);
		}
		if (mode == 1 && *placeholder++ == 'c')
		{	
			putchar(va_arg(args, int));
			placeholder++;
		}
		mode = 0;
		placeholder++;
	}
}

int	ft_printf(const char *placeholder, ...)
{
	int	i;

	i = 0;
	va_list	args;
	va_start(args, placeholder);
	
	printer(placeholder, args);

	va_end(args);
	return (0);
}

int	main()
{
 	ft_printf("Print a character %c. Done!\n", 'H');
}
