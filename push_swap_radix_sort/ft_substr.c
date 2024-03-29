/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 17:52:32 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:25:52 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buff;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (*s == '\0' || start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	buff = malloc(len * sizeof(char) + 1);
	substr = buff;
	if (!buff)
		return (0);
	while (s[start] && len > 0)
	{	
		*buff = s[start];
		buff++;
		start++;
		len--;
	}
	*buff = '\0';
	ft_memcpy(substr, buff, len);
	return (substr);
}

/*int	main(void)
{
	char	string[] = "Drinkin' this rain, I'm on fire.";

	printf("%s\n", ft_substr(string, 14, 4));
}*/
