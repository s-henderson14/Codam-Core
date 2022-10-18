/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:09:47 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/12 10:59:53 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*ps;
	unsigned char	pc;

	i = 0;
	pc = (unsigned char) c;
	ps = (void *) s;
	if (n == 0)
		return (0);
	while (i < n)
	{	
		if (*ps == pc)
			return (ps);
		else
		{	
			ps++;
			i++;
		}
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
