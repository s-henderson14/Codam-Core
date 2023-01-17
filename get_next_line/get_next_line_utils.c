/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:20 by shenders          #+#    #+#             */
/*   Updated: 2023/01/17 17:51:16 by shenders         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *) dst;
	psrc = (char *) src;
	if (!psrc && !dst)
		return (0);
	while (n != 0)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (dst);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buff;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (*s == '\0' || start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	buff = malloc(len * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	substr = buff;
	while (s[start] && len > 0)
	{
		*buff = s[start];
		buff++;
		start++;
		len--;
	}
	*buff = '\0';
	ft_memcpy(substr, buff, len);
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buff = malloc(len1 + len2 + 1);
	if (!buff)
		return (free(s1), NULL);
	ft_memcpy(buff, s1, len1);
	ft_memcpy(buff + len1, s2, len2);
	buff[len1 + len2] = '\0';
	free(s1);
	return (buff);
}
