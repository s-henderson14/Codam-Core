/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:47:45 by shenders          #+#    #+#             */
/*   Updated: 2022/11/24 16:06:17 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		exit(1);
	while (s[i])
	{	
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/*int	main()
{
	print_string("");
}*/
