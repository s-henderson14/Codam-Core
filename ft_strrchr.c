/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:53:18 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/11 16:21:55 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	char			*ps;

	ps = (char *) s;
	c = (char) c;
	i = strlen(ps) + 1;
	while (ps[i] != s[0])
	{	
		if (ps[i] == c)
			return (&ps[i]);
		i--;
		if (ps[i] == '\0' && c == '\0')
			return (&ps[i]);
	}
	return (0);
}

/*int	main(void)
{
	char	string[] = "This is my string";

	printf("%s\n", ft_strrchr(string, 'i'));
	printf("%s\n", ft_strrchr(string, 'O'));
	printf("%s\n", ft_strrchr(string, 'g'));
	printf("%s\n", ft_strrchr(string, '\0'));
	printf("%s\n", ft_strrchr(string, 't'));
	printf("\n");
	printf("%s\n", strrchr(string, 'i'));
	printf("%s\n", strrchr(string, 'O'));
	printf("%s\n", strrchr(string, 'g'));
	printf("%s\n", strrchr(string, '\0'));
	printf("%s\n", strrchr(string, 't'));
}*/
