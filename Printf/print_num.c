/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:31:53 by shenders          #+#    #+#             */
/*   Updated: 2022/11/21 11:44:25 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include "printf.h"

static int	num_len(int p)
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
		return ((char *)"2147483648");
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

/*int	main(void)
{
	printf("%s\n", print_num(456));
}*/
