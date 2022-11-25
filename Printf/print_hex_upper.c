/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:47:06 by sean              #+#    #+#             */
/*   Updated: 2022/11/25 09:55:39 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

static int	num_len(unsigned long p)
{
	int	count;

	count = 0;
	while (p != 0)
	{	
		count++;
		p /= 16;
	}
	return (count);
}

int	print_hex_upper(unsigned long n)
{	
	int		len;
	char	*hex;
	char	*str;

	len = num_len(n);
	hex = "0123456789ABCDEF";
	str = malloc(len * sizeof(unsigned int) + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[--len] = hex[0];
	while (n != 0)
	{	
		str[--len] = hex[n % 16];
		n = n / 16;
	}
	print_string(str);
	return ((int)strlen(str));
}

/*int	main(void)
{	
	void 	*ptr;

	ptr = NULL;
	printf("%p\n", &ptr);
	print_hex(&ptr);
}*/