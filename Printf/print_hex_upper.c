/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:47:06 by sean              #+#    #+#             */
/*   Updated: 2022/11/25 15:04:38 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

static int	num_len(unsigned int p)
{
	int	count;

	count = 0;
	if (p == 0)
		count++;
	while (p != 0)
	{	
		p /= 16;
		count++;
	}
	return (count);
}

int	print_hex_upper(unsigned int n)
{	
	int		len;
	char	*hex;
	char	*str;

	len = num_len(n);
	hex = "0123456789ABCDEF";
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{	
		str[--len] = hex[n % 16];
		n = n / 16;
	}
	print_string(str);
	len = ((int) strlen(str));
	free(str);
	return (len);
}

/*int	main(void)
{	
	void 	*ptr;
	ptr = NULL;
	printf("%p\n", &ptr);
	print_hex(&ptr);
}*/