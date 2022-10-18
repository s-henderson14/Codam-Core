/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <shenders@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:17:37 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/05 17:09:31 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int arg);

int	ft_isalpha(int arg)
{
	if ((arg >= 97 && arg <= 122) || (arg >= 65 && arg <= 90))
		return (1);
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('B'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", ft_isalpha(1));
	printf("%d\n", ft_isalpha('&'));
	printf("%d\n", isalpha('a'));
	printf("%d\n", isalpha('B'));
	printf("%d\n", isalpha('1'));
	printf("%d\n", isalpha(1));
	printf("%d\n", isalpha('&'));
}
