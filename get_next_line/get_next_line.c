/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:09 by shenders          #+#    #+#             */
/*   Updated: 2023/01/03 17:16:58 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 39
#endif

char	*get_next_line(int fd)
{	
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*nextline;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (nextline != 0)
		line = nextline;
	else if (nextline == 0)
		line = strdup("");
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{	
		buf[bytes_read] = '\0';
		if (bytes_read < BUFFER_SIZE)
			return (ft_strjoin(line, find_char(buf, '\0')));
		else if (find_char(buf, '\n') == NULL)
			line = ft_strjoin(line, buf);
		else
		{	
			line = ft_strjoin(line, find_char(buf, '\n'));
			nextline = linecut(buf, '\n');
			return (line);
		}
	}
	return (NULL);
}

/*int	main(void)
{
	int	fd;
	
	fd = open("dhumma.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	if (get_next_line(fd) == NULL)
		return(-1);
	return (0);		
}*/