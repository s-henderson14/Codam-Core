/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:52:06 by shenders          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:47 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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

int	print_nbr(int n)
{
	int	len;
	int	i;

	i = 0;
	len = num_len(n);
	if (n == -2147483648)
	{	
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{	
		print_char('-');
		print_nbr(n * (-1));
	}
	else if (n > 9)
	{
		print_nbr(n / 10);
		print_nbr(n % 10);
	}
	else if (n <= 9)
		print_char('0' + n);
	return (len);
}

/*int	main()
{
	print_nbr(456);
}*/
