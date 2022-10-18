/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:19:52 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/05 17:25:24 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int arg);

int	ft_isascii(int arg)
{
	if (arg >= 0 && arg <= 127)
		return (1);
	return (0);
}

int	main(void)
{
	printf("%d", ft_isascii('a'));
	printf("%d", ft_isascii('5'));
	printf("%d", ft_isascii('*'));
	printf("%d", ft_isascii(9));
	printf("%d", ft_isascii("234"));
	printf("\n");
	printf("%d", isascii('a'));
	printf("%d", isascii('5'));
	printf("%d", isascii('*'));
	printf("%d", isascii(9));
	printf("%d", isascii("234"));
}
