/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:45:39 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/07 16:36:56 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;
	unsigned int	n;

	ch = b;
	n = 0;
	while (n < len)
	{	
		*ch = (unsigned char) c;
		ch++;
		len--;
	}
	return (b);
}

/*int	main(void)
{
	char	string[] = "Hello";

	printf("%s", ft_memset(string, '.', 3));
	printf("\n");
	printf("%s", memset(string, '.', 3));
}*/
