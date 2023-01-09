/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:20 by shenders          #+#    #+#             */
/*   Updated: 2023/01/09 12:21:08 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>


size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}
char	*join_and_free(char* line, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(line, buf);
		if (!tmp)
			return (free(tmp),NULL);
	free(line);
	return (tmp);		
}

char    *ft_strchr(const char *s, int c)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	char	*buff;
	size_t	len1;
	size_t	len2;
	int		tot;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buff = malloc((len1 + len2) * sizeof(char) + 1);
	concat = buff;
	tot = len1 + len2;
	if (!buff)
	{	
		free(buff);
		return (free(concat),NULL);
	}
	memmove(buff, s1, len1);
	memmove(buff + len1, s2, len2);
	buff[tot] = '\0';
	return (concat);
}

char	*get_line(char *txt)
{
	int	i;
	char	*line;

	i = 0;
	if (!txt[i])
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (txt[i] && txt[i] != '\n')
	{	
		line[i] = txt[i];
		i++;
	}
	if (txt[i] && txt[i] == '\n')
		line[i++] = '\n';
	return (line);	
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
