/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 10:57:40 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/29 18:42:44 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*buff;
	size_t		i;
	size_t		j;
	
	i = 0;
	if (!s1 || !set)
		return (0);
	while (set[i] && ft_strchr(set, s1[i]))
		i++;
	j = 0;
	len = ft_strlen(s1);	
	while (set[j] && ft_strrchr(set, s1[j]))
	{	
		len--;
		j++;
	}
	buff = (char *)malloc(sizeof(char) * (len - i) + 1);
	if (!buff)
		return (0);
	buff = (char *) s1;
	return (ft_substr(buff, i, len + 1));
}

/*int	main()
{
	char	s1[] = "Hello";
	char	set[] = "lo";

	printf("%s", ft_strtrim(s1, set));
}*/
