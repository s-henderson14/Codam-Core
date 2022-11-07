#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:34:27 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/07 18:05:22 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

size_t word_count(const char *s, char c)
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

size_t	word_len(const char *s, int start, char c)
{
	int	count;

	count = 0;	
	while (s[start] && s[start] == c)
		start++;
	while (s[start] && s[start] != c)
	{	
		count++;
		start++;
	}
	return (count);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{ 
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	size_t	i;
	size_t	end;
	size_t	start;

	start = 0;
	i = 0;
	end = word_count(s, c);
	temp = (char **) malloc(sizeof(char *) * (end + 1));
	if (!temp)
		return (NULL);
	temp[end] = NULL;
	while (start < end)
	{	
		if (s[i] != c)
		{	
			temp[start] =  ft_substr((char *)s,  i, word_len(s, i, c));
			if (!temp[start])
				free_array(temp);
			start++;
		}
		i++;	
		i = i + word_len(s, i, c);
	}	
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
