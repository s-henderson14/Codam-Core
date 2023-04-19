/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:20 by shenders          #+#    #+#             */
/*   Updated: 2023/01/24 16:27:03 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	size_t	i;

	i = 0;
	pdst = (char *) dst;
	psrc = (char *) src;
	if (!psrc && !dst)
		return (0);
	while (i != n)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		n++;
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
		return (NULL);
	else
	{
		ft_memcpy(buff, s1, len);
		buff[len] = '\0';
		return (buff);
	}
}

char	*get_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buff;

	i = 0;
	if (!s)
		return (NULL);
	buff = malloc(len * (sizeof(char)) + 1);
	if (!buff)
		return (NULL);
	while (s[start] && i < len)
		buff[i++] = s[start++];
	buff[i] = '\0';
	return (buff);
}

char	*gnline_join(char *s1, char *s2, int free_s1)
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
	if (free_s1)
		free(s1);
	buff[len1 + len2] = '\0';
	return (buff);
}
