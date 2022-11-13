/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:12:45 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:18:06 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{	
		c += 32;
		return (c);
	}
	return (c);
}

/*int	main(void)
{
	printf("%c", ft_tolower('C'));
	printf("%c", ft_tolower('2'));
	printf("%c", ft_tolower('T'));
	printf("%c", ft_tolower('t'));
	printf("%c", ft_tolower('*'));
}*/	
