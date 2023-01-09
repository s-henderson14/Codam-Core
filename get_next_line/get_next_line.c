/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:59 by shenders          #+#    #+#             */
/*   Updated: 2023/01/09 14:26:26 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include "get_next_line_utils.c"
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 10
#endif

char	*readfile(int fd, char *line)
{
	char	*buffer;
	int		bytes_read;

	if (!line)
		line = malloc(sizeof(char) * 1);
	if (!line)
		return (free(line), NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		line = join_and_free(line, buffer);
		if (!line)
			return (free(line), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*getline_(char *txt)
{
	int		i;
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

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0 < 0))
		return (NULL);
	buf = readfile(fd, buf);
	if (!buf)
		return (free(buf), NULL);
	line = getline_(buf);
	if (!line)
		return (free(line), NULL);
	buf = over_read(buf);
	return (line);
}

/*int main(void)
{   
    int fd;

    fd = open("dhamma.txt", O_RDONLY);
    if (fd == (-1))
        return (-1);
    printf("%s", get_next_line(fd)); 
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd)); 
    return (0);
}*/