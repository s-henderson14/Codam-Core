/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:33:05 by shenders          #+#    #+#             */
/*   Updated: 2022/12/05 13:00:07 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_char(int c)
{	
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/*int	main()
{
	print_char('y');	
}*/
