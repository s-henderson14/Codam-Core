/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:50:29 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/16 18:33:24 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *hs, const char *n, size_t len);

char	*ft_strnstr(const char *hs, const char *n, size_t len)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (n[j] == '\0')
		return ((char *) hs);
	while (hs[i] != '\0' && len > 0)
	{
		if (hs[i] == n[j])
		{	
			i++;
			j++;
			len--;
			if (n[j] == '\0')
				return ((char *) &hs[i - j]);
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
