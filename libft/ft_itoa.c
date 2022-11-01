/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:57:14 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/30 18:05:17 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static	unsigned int	num_len(int p)
{
	int count;

	count = 0;
	if (p == 0)
		return (1);
	if (p < 0)
	{	
		count += 1;
		p = p * (-1);
	}
	while (p != 0)
	{	
		count++;
		p /= 10;
	}
	return (count);
}


char	*ft_itoa(int n);

char	*ft_itoa(int n)
{	
	char	*str;
	size_t	len;

	len = num_len(n);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return(0);
	str[len] = '\0';
	if (n == INT_MIN)
		return(ft_memcpy(str, "-2147483648", 12)); 
	if (n < 0)
        {
                n = n * (-1);
                str[0] = '-';
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
