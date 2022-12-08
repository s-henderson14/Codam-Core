/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:32:50 by shenders          #+#    #+#             */
/*   Updated: 2022/12/05 13:39:20 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	strl(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

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
	{	
		free(str);
		return (-1);
	}
	str[len] = '\0';
	if (n == 0)
		str[0] = hex[0];
	while (n != 0)
	{	
		str[--len] = hex[n % 16];
		n = n / 16;
	}
	if (print_string(str) == -1)
		return (-1);
	len = (strl(str));
	free(str);
	return (len);
}

/*int	main(void)
{	
	void 	*ptr;
	ptr = NULL;
	
	printf("%x\n", -10);
	print_hex_lower(-10);
}*/
