/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 15:35:05 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/27 16:37:43 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buff;
	char			*temp;

	if (!s || !f)
		return (0);
	buff = (char *)malloc(ft_strlen(s) + 1);
	if (!buff)
		return (0);
	i = 0;
	temp = (char *)s;
	while (s[i])
	{	
		buff[i] = f(i, temp[i]);
		i++;
	}
	buff[i] = 0;
	return (buff);
}
