/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:27:39 by shenders          #+#    #+#             */
/*   Updated: 2023/01/09 15:28:21 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buff = malloc((len1 + len2) * sizeof(char) + 1);
	if (!buff)
		return (free(buff), NULL);
	memmove(buff, s1, len1);
	memmove(buff + len1, s2, len2);
	buff[len1 + len2] = '\0';
	return (buff);
}

char	*join_and_free(char *line, char *buf)
{
	char	*tmp;
	
	if(!line || !buf)
		return (NULL);
	tmp = ft_strjoin(line, buf);
	if (!tmp)
		return (free(tmp), NULL);
	free(line);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char) c == '\0')
		return ((char *) s);
	else
		return (0);
}

char	*over_read(char *txt)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	if (!txt[i])
		return (free(txt), NULL);
	line = malloc((ft_strlen(txt) - i + 1) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	i++;
	j = 0;
	while (txt[i])
	{	
		line[j] = txt[i];
		i++;
		j++;
	}
	free(txt);
	return (line);
}
