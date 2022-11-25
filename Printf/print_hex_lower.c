/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:32:50 by shenders          #+#    #+#             */
/*   Updated: 2022/11/25 14:57:57 by shenders         ###   ########.fr       */
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

int	print_hex_lower(unsigned int n)
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
	if (n == 0)
		str[0] = hex[0];
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
	
	printf("%x\n", 3354556);
	print_hex_lower(0);
}*/
