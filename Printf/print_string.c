/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:47:45 by shenders          #+#    #+#             */
/*   Updated: 2022/12/05 13:41:13 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{	
		if (print_string ("(null)") == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{	
		if (print_char(s[i]) == (-1))
			return (-1);
		i++;
	}
	return (i);
}

/*int	main()
{	
	char	*x;

	x = NULL;
	print_string(x);
}*/