/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 10:57:40 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/03 09:17:51 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]))
		i++;
	j = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strrchr(set, s1[len - 1]))
	{	
		len--;
		j++;
	}
	str = ft_substr(s1, i, len - i);
	return (str);
}

/*int	main()
{
	char	s1[] = "";
	char	set[] = "";

	printf("%s", ft_strtrim(s1, set));
}*/
