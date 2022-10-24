/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:09:47 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/14 13:25:46 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	int	i;
	
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
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	//char    string[] = "Finish part one today";
	
	printf("%s", (char *)ft_memchr(tab, -1, 7));

	printf("%s\n", ft_memchr(string, 'o', 13));
	printf("%s\n", ft_memchr(string, 'o', 12));
	printf("%s\n", ft_memchr(string, 'i', 0));
	printf("\n");
	printf("%s\n", memchr(string, 'o', 13));
	printf("%s\n", memchr(string, 'o', 12));
	printf("%s\n", memchr(string, 'i', 0));
}*/
