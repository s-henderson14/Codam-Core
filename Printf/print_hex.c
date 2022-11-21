/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:32:50 by shenders          #+#    #+#             */
/*   Updated: 2022/11/21 14:59:39 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

int	print_hex(unsigned int n)
{
	int	num_l;

	num_l = num_len(n); 
	if (n == -2147483648)
	{	
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		print_char('-');
		print_hex(n * (-1));
	}
	else if (n > 9)
	{
		print_hex(n / 16);
		print_hex(n % 10);
	}
	else if (n <= 9)
		print_char('0' + n);
	return(num_l);
}

/*int	main()
{
	print_hex(456);
}*/