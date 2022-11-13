/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:04:14 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:06:30 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isalnum(int c);

int	ft_isalnum(int c)

{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('B'));
	printf("%d", ft_isalnum(0));
	printf("%d", ft_isalnum('0'));
	printf("%d", ft_isalnum(345));
	printf("%d", ft_isalnum(234));
	printf("\n");
	printf("%d", isalnum('a'));
	printf("%d", isalnum('B'));
	printf("%d", isalnum(0));
	printf("%d", isalnum('0'));
	printf("%d", isalnum(345));
	printf("%d", isalnum(234));
}*/
