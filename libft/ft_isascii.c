/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:19:52 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/18 20:51:28 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	int i;
	
	printf("%d", ft_isascii('a'));
	printf("%d", ft_isascii('5'));
	printf("%d", ft_isascii('*'));
	printf("%d", ft_isascii(9));
	printf("%d", ft_isascii(0));
	printf("\n");
	printf("%d", isascii('a'));
	printf("%d", isascii('5'));
	printf("%d", isascii('*'));
	printf("%d", isascii(9));
	printf("%d", isascii(0));

	i = 128;
    while (i <= 138)
    {
        printf("%d",ft_isascii(i));
        i++;
    }
}*/
