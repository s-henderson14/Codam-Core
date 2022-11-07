/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:34:27 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/07 17:13:20 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int word_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
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

void	free_m(char *strings)
{
	int	i;

	i = 0;
	while (strings[i] != '\0')
	{	
		free(strings);
		i++;
	}
	free(strings);
}

char	**ft_split(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int	i;
	int	j;
	int start;

	i = 0;
	start = 0;
	j = word_count(s, c);
	temp = (char **) malloc(sizeof(char *) * j + 1);
	if (!temp)
		return(0);
	temp[j] = NULL;
	while (s[i])
	{	
		while (s[i] == c)
			i++;
		if (s[i] != c)
			temp[i] =  ft_substr((char *)s, start + i, word_len(s, i, ' '));
		if (!temp[i])
				free_m(*temp);
	}
	i++;	
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
	static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, j);
	return (word);
}
