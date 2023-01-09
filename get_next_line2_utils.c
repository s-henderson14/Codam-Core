/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sean <Sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:20 by shenders          #+#    #+#             */
/*   Updated: 2023/01/09 00:54:57 by Sean             ###   ########.fr       */
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
	substr = buff;
	if (!buff)
		return (free(buff), NULL);
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

char	*newline_present(char *txt)
{
	int	    i;
    char    *line;

	i = 0;
	line = NULL;
	while (txt[i])
	{	
		if (txt[i] == '\n')
		{	
			line = ft_substr(txt, 0, i + 1);
            if(!line)
                return(free(line), NULL);
            return (line);
		}    
		i++;
	}
	return (line);
}

char	*bytes_after_newline(char *txt)
{
	int		i;
	char	*after_newline;

	i = 0;
	while (txt[i])
	{	
		if (txt[i] == '\n')
		{	
			i++;
			if (!txt[i])
				return (NULL);
			else if (txt[i])
			{	
                after_newline = ft_substr(txt, i, ft_strlen(txt) - i);
                if (!after_newline)
                    return (free(after_newline), NULL);
			    return (after_newline);
            }
		}
		i++;
	}
	return (NULL);
}
