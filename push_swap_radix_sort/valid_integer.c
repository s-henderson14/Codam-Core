/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_integer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 13:02:21 by shenders      #+#    #+#                 */
/*   Updated: 2023/03/06 13:04:59 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{	
		if (!str[1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
