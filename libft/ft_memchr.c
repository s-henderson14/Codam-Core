/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:09:47 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:21:32 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	int				i;

	i = 0;
	ps = (unsigned char *) s;
	if (n == 0)
		return (0);
	while (n > 0)
	{	
		if (*(ps + i) == (unsigned char)c)
			return (ps + i);
		i++;
		n--;
	}
	return (0);
}

/*int	main(void)
{
	char	string[] = "Finish part one today";

	printf("%s\n", ft_memchr(string, 'o', 13));
	printf("%s\n", ft_memchr(string, 'o', 12));
	printf("%s\n", ft_memchr(string, 'i', 0));
	printf("\n");
	printf("%s\n", memchr(string, 'o', 13));
	printf("%s\n", memchr(string, 'o', 12));
	printf("%s\n", memchr(string, 'i', 0));
}*/
