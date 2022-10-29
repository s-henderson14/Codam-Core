/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 10:57:40 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/24 14:57:32 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{	
	unsigned int	i;
	char		*start;
	char		*end;
	
	i = 0;
	start = (char *)&s1[i];
	end =  (char *)&s1[ft_strlen(s1)] - 1; 
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	while ( start && end && i <= ft_strlen(set))
	{	
		if (&s1[i] == start)
			start[i++];
		else if (&s1[i] == end)
			end[i--];
		if ((!i) > 0 || (!i) < 0)
		return ((char *)s1 + i);
	}
	return (0);
}

/*int	main()
{
	char	s1[] = "Hello";
	char	set[] = "lo";

	printf("%s", ft_strtrim(s1, set));
}*/
