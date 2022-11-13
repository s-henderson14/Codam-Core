/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:06:11 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:17:49 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"
#include <stdio.h>
#include <ctype.h>*/

int	ft_toupper(int c);

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{	
		c -= 32;
		return (c);
	}
	else
		return (c);
}

/*int	main(void)
{	
	printf("%c", ft_toupper('c'));
	printf("%c", ft_toupper('!'));
	printf("%c", ft_toupper('2'));
	printf("%c", ft_toupper('z'));
	printf("%c", ft_toupper('C'));
}*/
