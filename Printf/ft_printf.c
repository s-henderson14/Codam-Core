/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:39 by sean              #+#    #+#             */
/*   Updated: 2022/11/20 18:36:23 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <unistd.h>

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int print_string(char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {    
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}

int	num_len(int p)
{
	int	count;

	count = 0;
	if (p == 0)    
		return (1);
	if (p < 0)
	{	
		count += 1;
		p = p * (-1);
	}
	while (p != 0)
	{	
		count++;
		p /= 10;
	}
	return (count);
}

char	*print_num(int n)
{	
	char	*str;
	size_t	len;

	len = num_len(n);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == INT_MIN)
		return ("2147483648");
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	if (n == 0)
        str[--len] = '0';
	while (n != 0)
	{	
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	printer(const char *fmt, va_list args)
{
	int		i;
	char	*s;
	
	while (*fmt)
	{	
		if (*fmt != '%')
			print_char(*fmt);
		else
		{	
			fmt++;
			if (*fmt == 'c')
			{	
				i = va_arg(args, int);
				print_char(i);
			}
			else if (*fmt == 's')
			{
				s = va_arg(args, char*);
				print_string(s);			
			}
			else if (*fmt == 'd')
			{	
				i = va_arg(args, int);
				print_string(print_num(i));
			}
		}	
	fmt++;
	}
}

int	ft_printf(const char *fmt, ...)
{	
	va_list	args;

	va_start(args, fmt);
	printer(fmt, args);
	va_end(args);
	return (0);
}

int	main(void)
{
	void	*ptr;

	ptr = NULL;
	printf("%d\n", ft_printf("%d", 55));
	ft_printf("Print the character %c.\n", 'H');
	ft_printf("If you could do a %s, I'd be impressed.\n", "word");
	ft_printf("But if you got me a number %d, now that would be something!\n", 5);
	ft_printf("So you really want to print a pointer? %p, woah you did!\n", ptr);
}