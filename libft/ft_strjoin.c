/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:07:35 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:26:49 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	char	*buff;
	size_t	len1;
	size_t	len2;
	int		tot;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buff = malloc((len1 + len2) * sizeof(char) + 1);
	concat = buff;
	tot = len1 + len2;
	if (!buff)
		return (0);
	else
	{	
		ft_memcpy(buff, s1, len1);
		ft_memcpy(buff + len1, s2, len2);
		buff[tot] = '\0';
	}
	return (concat);
}

/*int	main(void)
{
	char	string1[] = "Mambo";
	char	string2[] = "Jambo";

	printf("%s\n", ft_strjoin(string1, string2));
}*/
