/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:09 by shenders          #+#    #+#             */
/*   Updated: 2022/11/25 14:26:13 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include <string.h>

static int	num_len(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
		count++;
	while (p != 0)
	{
		count++;
		p /= 16;
	}
	return (count);
}

int	print_pointer(void *add)
{
	int				len;
	char			*hex;
	char			*str;
	unsigned long	i;

	i = (unsigned long) add;
	len = num_len(i);
	hex = "0123456789abcdef";
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	print_string("0x");
	if (i == 0)
		str[--len] = hex[0];
	while (i != 0)
	{
		str[--len] = hex[i % 16];
		i = i / 16;
	}
	print_string(str);
	len = ((int)strlen(str) + 2);
	free(str);
	return (len);
}

/*int    main(void)
{    
	int	*ptr;
	
	ptr = NULL;
	ft_printf("%p\n", (void *)ptr);
	printf("%p", (void *)ptr);
}*/