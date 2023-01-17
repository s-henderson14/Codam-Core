/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:02:38 by Sean              #+#    #+#             */
/*   Updated: 2023/01/17 18:06:00 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include "get_next_line_utils.c"
#include <string.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 10
#endif

char	*newline_present(char *txt)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (txt[i])
	{	
		if (txt[i] == '\n')
		{	
			line = ft_substr(txt, 0, i + 1);
			if (!line)
				return (free(txt), NULL);
			return (free(txt), line);
		}
		i++;
	}
	free(txt);
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
			after_newline = ft_substr(txt, i, (ft_strlen(txt) - i + 1));
			if (!after_newline)
				return (NULL);
			return (after_newline);
		}
		i++;
	}
	return (NULL);
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

char	*readfile(int fd, char *txt_cont)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(txt_cont, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		txt_cont = ft_strjoin(txt_cont, buffer);
		if (!txt_cont)
			return (NULL);
	}
	return (txt_cont);
}

char	*get_next_line(int fd)
{
	char		*txt_container;
	static char	*excess;

	if (fd < 1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	txt_container = strdup("");
	if (!txt_container)
		return (free(txt_container), NULL);
	if (excess)
		txt_container = excess;
	txt_container = readfile(fd, txt_container);
	if (!txt_container[0] || !txt_container)
		return (free(txt_container), NULL);
	if (ft_strchr(txt_container, '\n'))
	{	
		excess = bytes_after_newline(txt_container);
		txt_container = newline_present(txt_container);
	}
	return (txt_container);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*string;

// 	fd = open("test.txt", O_RDONLY);
// 	string = get_next_line(fd);
// 	printf("%s", string);
// 	while (string)
// 	{
// 		string = get_next_line(fd);
// 		printf("%s", string);
// 	}
// 	return (0);
// }
