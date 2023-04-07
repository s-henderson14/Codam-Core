/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:48:46 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/06 13:33:36 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		index;
	unsigned long	number;
	int		minus;
	int		int_ret;

	index = 0;
	number = 0;
	minus = 1;
	if (str[index] == 45)
	{	
		minus = minus * (-1);
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
	{
		number = (number * 10) + (str[index++] - '0');
		if (number > INT_MAX)
			error_message();
	}
	int_ret = (int)number;
	return (int_ret * minus);
}
