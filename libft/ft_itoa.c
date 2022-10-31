/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:57:14 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/31 14:31:04 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static	unsigned int	num_len(int p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (1);
	if (p < 0)
	{	
		len += 1;
		p = p * (-1);
	}		
	while (p != 0)
	{	
		p /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n);

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = num_len(n);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (n == INT_MIN)
		return (ft_memcpy(str, "-2147483648", 12));
	str[len] = '\0';
	if (n < 0)
	{	
		str[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{	
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

/*int	main(void)
{
	printf("%s", ft_itoa(45));
}*/
