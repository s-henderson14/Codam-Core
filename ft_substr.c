/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 17:52:32 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/17 18:50:09 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buff;
	size_t	s_len;

	s_len = strlen(s);
	buff = malloc(len * sizeof(char) + 1);
	substr = buff;
	if (!buff)
		return (0);
	if (*s == '\0')
		return (0);
	while (s[start] && len > 0)
	{	
		*buff = s[start];
		buff++;
		start++;
		len--;
	}
	*buff = '\0';
	memcpy(substr, buff, len);
	return (substr);
}

/*int	main(void)
{
	char	string[] = "Drinkin' this rain, I'm on fire.";

	printf("%s\n", ft_substr(string, 14, 4));
}*/
