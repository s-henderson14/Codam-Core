/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:28:23 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/05 17:36:01 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int arg);

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}

int	main(void)
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
}
