/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:50:29 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/28 17:03:55 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{	
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{	
				if (needle[j + 1] == '\0')
					return ((char *) &haystack[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}	

/*int	main(void)
{
	char	haystack[30] = "aaabcabcd";
	char	needle[] = "aabc";

	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("%s\n", strnstr(haystack, needle, -1));
	//printf("%s\n", ft_strnstr(haystack, needle, 19));
	//printf("%s\n", ft_strnstr(haystack, needle, 5));
	//printf("%s\n", ft_strnstr(haystack, word, 20));
	//printf("\n");
	//printf("%s\n", strnstr(haystack, needle, 20));
	//printf("%s\n", strnstr(haystack, needle, 19));
	//printf("%s\n", strnstr(haystack, needle, 5));
	//printf("%s\n", strnstr(haystack, word, 20));
}*/
