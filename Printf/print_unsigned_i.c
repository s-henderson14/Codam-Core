/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:56:51 by sean              #+#    #+#             */
/*   Updated: 2022/12/01 15:32:37 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int p)
{
	int	count;

	count = 0;
	if (p == 0)
		return (1);
	if (p < 0)
		p = p * (-1);
	while (p != 0)
	{	
		count++;
		p /= 10;
	}
	return (count);
}

int	print_unsigned_i(unsigned int n)
{
	int	len;

	len = num_len(n);
	if (n < 0)
		print_unsigned_i(n * (-1));
	else if (n > 9)
	{
		print_unsigned_i(n / 10);
		print_unsigned_i(n % 10);
	}
	else if (n <= 9)
		if (print_char('0' + n) == -1)
			return (-1);
	return (len);
}

/*int main()
{
    printf("%u", -1);
    print_unsigned_i(-1);
}*/