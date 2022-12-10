/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:20 by shenders          #+#    #+#             */
/*   Updated: 2022/12/10 17:07:53 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buff;
	size_t	s_len;

	s_len = strlen(s);
	if (*s == '\0' || start > s_len)
		return (strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	buff = malloc(len * sizeof(char) + 1);
	substr = buff;
	if (!buff)
		return (0);
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

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *concat;
        char    *buff;
        size_t  len1;
        size_t  len2;
        int             tot;

        len1 = strlen(s1);
        len2 = strlen(s2);
        buff = malloc((len1 + len2) * sizeof(char) + 1);
        concat = buff;
        tot = len1 + len2;
        if (!buff)
                return (0);
        else
        {
                memmove(buff, s1, len1);
                memmove(buff + len1, s2, len2);
                buff[tot] = '\0';
        }
        return (concat);
}

char	*linecut(char *line, int c)
{
	int		i;
	int		j;
	char	*line_end;

	i = 0;
	j = 0;
	line_end = NULL;
	while (line[i])
	{
		if (line[i] == c)
		{	
			i++;
			if (line[i] == '\0') // if we find a null terminator directly after the '\n' then we haven't anything extra to cut from our line. 
				return(0);
			else
				line_end = ft_substr(line, i, strlen(line) - i);	
			return (line_end);
		}
		i++;
	}		
	return (0);
}