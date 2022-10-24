/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 17:58:06 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/17 18:49:04 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1);

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	buff = (char *) malloc (len * sizeof(char) + 1);
	if (!buff)
		return (0);
	else
	{	
		ft_memcpy(buff, s1, len);
		buff[len] = '\0';
		return (buff);
	}		
}

/*int	main(void)
{
	char	string[] = "Ya dun know";

	printf("%s\n", ft_strdup(string));
	printf("%s\n", strdup(string));
}*/
