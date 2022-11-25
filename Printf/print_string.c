/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:47:45 by shenders          #+#    #+#             */
/*   Updated: 2022/11/25 14:36:33 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		exit(1);
	while (*s)
	{	
		print_char(*s);
		s++;
		i++;
	}
	return (i);
}

/*int	main()
{
	print_string("");
}*/