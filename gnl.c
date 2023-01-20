/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sean <Sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:02:38 by Sean              #+#    #+#             */
/*   Updated: 2023/01/20 11:18:27 by Sean             ###   ########.fr       */
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

char	*readfile(int fd, char *txt_cont)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	static char	*cont;

	cont = malloc(sizeof(char));
	if (!cont)
		return (NULL);
	cont[0] = '\0';	
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		txt_cont = ft_strjoin(cont, buffer);
		if (!txt_cont)
			return (NULL);
	}
	return (free(cont), txt_cont);
}

char	*get_next_line(int fd)
{
	static char	*txt_container;
	char		*line;
	char		*excess;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (!txt_container)	
		txt_container = "";	
	excess = bytes_after_newline(txt_container);
	if (excess)
		txt_container = ft_strjoin(excess, txt_container);
	txt_container = readfile(fd, txt_container);
	if (!txt_container[0] || !txt_container)
		return (NULL);
	line = newline_present(txt_container);
	if (!line)
		return (free(line), free(excess), NULL);
	return (free(excess),line);
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
