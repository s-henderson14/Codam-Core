/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:32:50 by shenders          #+#    #+#             */
/*   Updated: 2022/11/25 09:52:27 by sean             ###   ########.fr       */
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
		p /= 16;
		count++;
	}
	return (count);
}

int	print_hex_lower(unsigned long n)
{	
	int		len;
	char	*hex;
	char	*str;

	len = num_len(n);
	hex = "0123456789abcdef";
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	str[len] = '\0';
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
