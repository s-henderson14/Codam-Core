/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_convert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 14:12:11 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/18 14:16:14 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	c_convert(int c)
{	
	write(1, &c, 1);
	return (1);
}

int	main()
{
	printf("%d", c_convert('h'));
}
