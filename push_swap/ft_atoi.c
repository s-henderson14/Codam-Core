/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 14:48:46 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/03 10:27:10 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	minus;

	index = 0;
	number = 0;
	minus = 1;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == 45 || str[index] == 43)
	{
		if (str[index] == 45)
			minus = minus * (-1);
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
		number = (number * 10) + (str[index++] - '0');
	if (number > INT_MAX)
		return (-1);
	else if (number < INT_MIN)
		return (0);
	return (number * minus);
}
