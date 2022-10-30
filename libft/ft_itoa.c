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

static	unsigned int num_len(int p)
{
	int len;

	len = 0;
	if (p == 0)
		return(0);
	if (p < 0)
		len += 1;
	while (p != 0)
	{	
		p /= 10;
		len++;
	}
	return (len);
}

static char *rev_string(char *str)
{
	size_t 	i;
	size_t	len;
	char	*temp;

	len = ft_strlen(str) - 1;
	i = 0;
	temp = str;
	while (str && (i < len / 2))
	{
		temp[i] = str[len];
		str[len] = str[i];
		str[i] = temp[i];
		i++;
	}
	return (str);
}

char	*ft_itoa(int n);

char	*ft_itoa(int n)
{
	int		i;
	int		number;	
	char	*str;
	size_t	len;

	i = 0;
	len = num_len(n);
	number = 0;
	if (!n)
		return (0);
	str = (char *) malloc(sizeof(char) * num_len(n));
	if (!str)
		return (0);
	if (n == 0)
	{	
		str[i] = '0';
		str[i++] = '\0';
		return (str);
	}
	if (n < 0)
	{
		n = n * (-1);
		str[i++] = '-';
	}
	while(len > 0)	
	{	
		str[i] = (number / 10) + (str[i] + '0');
		len--;
	}
	return (rev_string(str));
}

/*int	main(void)
{
	printf("%s", ft_itoa(45));
}*/
