/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:28:23 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/14 13:21:06 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c);

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isprint('a'));
	printf("%d", ft_isprint('B'));
	printf("%d", ft_isprint(0));
	printf("%d", ft_isprint('0'));
	printf("%d", ft_isprint(345));
	printf("%d", ft_isprint(234));
	printf("\n");
	printf("%d", isprint('a'));
	printf("%d", isprint('B'));
	printf("%d", isprint(0));
	printf("%d", isprint('0'));
	printf("%d", isprint(345));
	printf("%d", isprint(234));
}*/
