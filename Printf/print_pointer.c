/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:09 by shenders          #+#    #+#             */
/*   Updated: 2022/11/21 18:50:54 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"
#include <string.h>
#include <stdio.h>

static int	num_len(int p)
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

int	print_pointer(int n)
{	
	int		len;
	int		i;
	char	*hex;
	char	*str;

	len = num_len(n);
	i = 0;
	hex = "0123456789abcdef";
	str = malloc(len * sizeof(char) + 1);
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

int	main(void)
{	
	void 	*ptr;

	ptr = NULL;
	printf("%x\n", &ptr);
	print_pointer(&ptr);
}