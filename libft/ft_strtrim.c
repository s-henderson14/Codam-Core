/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 10:57:40 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/29 17:23:22 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	char			*buff;

	start = 0;
	if (!s1 || !set)
		return (0);
	buff = (char *) malloc(len * sizeof(char) + 1);
	if (!buff)
		return (0);
	buff = (char *) s1;
	while (*buff && ft_strchr(set, *buff))
		buff++;
	len = ft_strlen(buff);	
	while (*(buff + len) && ft_strrchr(set, *(buff + len)))
		len--;
	return (ft_substr(buff, 0, len + 1));
}

/*int	main()
{
	char	s1[] = "Hello";
	char	set[] = "lo";

	printf("%s", ft_strtrim(s1, set));
}*/
