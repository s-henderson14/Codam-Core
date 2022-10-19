/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:53:18 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/19 17:31:30 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ps;

	i = ft_strlen(s);
	ps = (char *)s;
	if (ps[i] == '\0' && (char) c == '\0')
		return (&ps[i]);
	while (i > 0)
	{	
		if (ps[i] == (char) c)
			return (&ps[i]);
		i--;
	}
	if (ps[i] == (char) c)
		return (&ps[i]);
	return (0);
}

/*int	main(void)
{
	char	string[] = "";

	printf("%s\n", ft_strrchr(string, '\0'));
	printf("\n");
	printf("%s\n", strrchr(string, '\0'));
}*/
