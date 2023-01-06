/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:20 by shenders          #+#    #+#             */
/*   Updated: 2023/01/06 18:32:40 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

char	*get_line(char *string, int c)
{	
	size_t	line_len;
	size_t		i;
	char	*line;

	i = 0;
	line_len = 0;
	if (strchr(string, '\n'))
		line_len = (int)ft_strlen(string) - (int)strlen(strchr(string, c));
	line = malloc(sizeof(char) * line_len + 2);
	if (!line)
		return(free(line), NULL);
	line[line_len] = '\0';
	line[line_len - 1] = '\n';
	while (line && string && i < line_len)
	{	
		line[i] = string[i];
		i++;
	}
	return (line);
}
char	*linecut(char *line, int c)
{
	int		i;
	char	*line_end;

	i = 0;
	line_end = NULL;
	while (line[i])
	{	
		if (line[i] == c)
		{	
			i++;
			if (line[i] == '\0')
				return (NULL);
			else if (line[i] != '\0')
			line_end = ft_substr(line, i, ft_strlen(line) - i);
			if (!line_end)
				return (free(line_end), NULL);
			return (line_end);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	int		tot;
	int	len1;
	int	len2;

	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen(s2);
	buff = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!buff)
		return (free(buff), NULL);
	tot = len1 + len2;
	memmove(buff, s1, len1);
	memmove(buff + len1, s2, len2);
	buff[tot] = '\0';
	return (free(s2),buff);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buff;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (*s == '\0' || start > s_len)
		return (strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	buff = malloc(len * sizeof(char) + 1);
	if (!buff)
		return (free(buff), NULL);
	substr = buff;
	while (s[start] && len > 0)
	{
		*buff = s[start];
		buff++;
		start++;
		len--;
	}
	*buff = '\0';
	memmove(substr, buff, len);
	return (substr);
}

size_t get_line_size(char *string, int c)
{	
	size_t	line_len;
	size_t		i;
	char	*line;

	
	i = 0;
	line_len = 0;
	if (strchr(string, '\n'))
		line_len = (int)ft_strlen(string) - (int)strlen(strchr(string, c));
	return (line_len);
}

char *reader(int fd, int readsize)
{	
	char		buf[readsize + 1];
	int		bytes_read;
	char	*line;
	char	*tmp;
	char	*txt;
	
	txt = '\0';
	bytes_read = 1;
	while (bytes_read >= 1)
	{	
		bytes_read = read(fd, buf, readsize);
		if (bytes_read == -1)
			break ;
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(buf, txt);
		if (!tmp)	
			return(free(tmp), NULL);
		line = tmp;
		if (bytes_read == 0)
			return (free(tmp),line);
	}
	return (NULL);
	
}