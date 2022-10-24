/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:50:29 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/24 10:22:32 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		if (haystack[i] == needle[j])
		{	
			i++;
			j++;
			len--;
			if (needle[j] == '\0')
				return ((char *) &haystack[i - j]);
		}
		else
		{	
			i++;
			j = 0;
			len--;
		}	
	}
	return (0);
}

/*int	main(void)
{
	char	haystack[] = "is there aaaaanybody in there";
	char	needle[] = "anybody";
	char	word[] = "";

	printf("%s\n", ft_strnstr(haystack, needle, 20));
	printf("%s\n", ft_strnstr(haystack, needle, 19));
	printf("%s\n", ft_strnstr(haystack, needle, 5));
	printf("%s\n", ft_strnstr(haystack, word, 20));
	printf("\n");
	printf("%s\n", strnstr(haystack, needle, 20));
	printf("%s\n", strnstr(haystack, needle, 19));
	printf("%s\n", strnstr(haystack, needle, 5));
	printf("%s\n", strnstr(haystack, word, 20));
}*/
