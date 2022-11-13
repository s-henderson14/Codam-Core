/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <shenders@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:02:44 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:04:44 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isdigit('a'));
	printf("%d", ft_isdigit('B'));
	printf("%d", ft_isdigit(0));
	printf("%d", ft_isdigit('0'));
	printf("%d", ft_isdigit(345));
	printf("%d", ft_isdigit(234));
	printf("\n");
	printf("%d", isdigit('a'));
	printf("%d", isdigit('B'));
	printf("%d", isdigit(0));
	printf("%d", isdigit('0'));
	printf("%d", isdigit(345));
	printf("%d", isdigit(234));
}*/
