/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:20:16 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/14 13:28:06 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	c = (char) c;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
		if (*s == '\0' && c == '\0')
			return ((char *) s);
	}
	return (0);
}

/*int	main(void)
{
	char	string[] = "Hello";

	printf("%s\n", ft_strchr(string, 'i'));
	printf("%s\n", ft_strchr(string, 'h'));
	printf("%s\n", ft_strchr(string, 'e'));
	printf("%s\n", ft_strchr(string, 't'));
	printf("%s\n", ft_strchr(string, '\0'));
	printf("%s\n", ft_strchr(string, 'o'));
	printf("\n");
	printf("%s\n", strchr(string, 'i'));
	printf("%s\n", strchr(string, 'h'));
	printf("%s\n", strchr(string, 'e'));
	printf("%s\n", strchr(string, 't'));
	printf("%s\n", strchr(string, '\0'));
	printf("%s\n", strchr(string, 'o'));
}*/
