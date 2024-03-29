/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:34:27 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:29:29 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{	
			i++;
			if (s[i] == c || s[i] == '\0')
				count++;
		}
	}
	return (count);
}

size_t	word_len(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{	
		count++;
		s++;
	}
	return (count);
}

void	free_m(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings[i]);
	free(strings);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	size_t	i;
	size_t	len;
	size_t	start;

	start = 0;
	i = 0;
	len = word_count(s, c);
	temp = (char **) malloc(sizeof(char *) * (len + 1));
	if (!temp)
		return (NULL);
	while (start < len)
	{	
		if (s[i] != c)
		{	
			temp[start] = ft_substr(s, i, word_len(s + i, c));
			if (!temp[start])
				return (free_m(temp), NULL);
			start++;
			i = i + word_len(s + i, c);
		}
		i++;
	}
	temp[len] = NULL;
	return (temp);
}

/*int	main()
{	
	int	i;
	char **arr;
	i = 0;
	arr = ft_split("Tripoille", 0);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	printf("%d\n", i);
}*/
