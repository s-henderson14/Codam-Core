/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 08:55:41 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/03 14:33:50 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	ft_occur(const char *str, char c)
{
	int	count;
	int	i;
	
	i =0;
	count = 0;
	while ( str[i] && str[i] == c)
	i++;
	while(str[i] && str[i] != c)
	{	
		if(str[i] != c && str[i + 1] == c)
			count++;
		i++;
	}
	return (count);
}	

char	**ft_split(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**temp;
	char	*str;
	int	i;
	int	j;
	int	start;

	start = 0;
	i = 0;
	j = 0;
	str = (char *)s;
	temp = (char **) malloc(sizeof(char *) * ft_occur(s, c) + 1);
	if (!temp)
		return(0);
	while (s[i])
	{	
		if ( s[i] == c)
		{
			temp[j] = ft_substr((char *)s, start, i);
			start = i + 1;
			j++;
		}
		i++;	
	}
	if (temp)
	{	
		temp[ft_occur(s, c) + 1] = NULL;	
		return (temp);
	}
	return (0);	

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
