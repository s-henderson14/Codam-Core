/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:34:27 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/07 16:38:43 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int word_count(const char *s, char c)
{
	int	count;
	int	i;

	i =0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while(s[i] && s[i] != c)
		{	i++;
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			{
				count++;
				i++;
			}
		}
	}
	return (count);
}

int	word_len(const char *s, int  start, char c)
{
	int	count;

	count = 0;
	while (s[start])
	{	
		while (s[start] == c)
			start++;
		while (s[start] != c)
		{	
			count++;
			start++;
		}

	}
	return (count);
}

char	**ft_split(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int	i;
	int start;

	start = 0;
	i = 0;
	temp = (char **) malloc(sizeof(char *) * word_count(s, c) + 1);
	if (!temp)
		return(0);
	while (s[i])
	{	
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{	
			*temp = ft_substr((char *)s, start + i, word_len(s, i, ' '));
			if (!*temp)
				free(*temp);
		}
		i++;
	}	
	temp[word_count(s, c)] = NULL;	
	return (temp);

}

/*int	main()
{
	int	i;
	char **arr;

	i = 0;
	arr = ft_split("Sean was not yet sure how the function worked", ' ');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	printf("%d\n", i);
}*/	
