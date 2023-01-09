#include <stdio.h>
#include <stdlib.h>
//#include "get_next_line_utils.c"
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 10
#endif

char	*readfile(int fd, char* line)
{
	char	*buffer;
	int		bytes_read;

	if(!line)
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
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (line);
}

char    *get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 1 || BUFFER_SIZE < 1)
        return (NULL);
	buf = readfile(fd, buf);
	if (!buf)
		return (NULL);
	line = get_line(buf);
	buf = over_read(buf);
	return (line);
}
