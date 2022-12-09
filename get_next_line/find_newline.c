#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "get_next_line_utils.c"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

int	find_new_line(char *text, int c)
{
	int	i;

	i = 0;
	if (!text[i])
		return (-1);
	while (text[i] != '\0')
	{	
		if (text[i] == (char)c)
			return (i);
		i++;
	}
	if (text[i] == '\0')
		return (i);			
	return (i);			
}

char	*readfile (int fd)
{	
	static char buf[BUFFER_SIZE + 1];
	char	*line;
	bool	keep_reading;
	
	keep_reading = true;
	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{	

		if (find_new_line(buf, '\n') == (-1)) // if error occurs when searching for '\n'. Free buffer and return error value.
			return (free(buf), "negative 1");
		if (find_new_line(buf, '\n') == 0) // if no occurences of a newline character are found return buf. 
		{	
			buf[BUFFER_SIZE] = '\0';	
			return (buf);
		}
		else
			ft_substr(line, 0, find_new_line(buf, '\n'));
	}
	return (0);	
}

int	main(void)
{
	int	fd;

	fd = open("dhamma.txt", O_RDONLY);
	if (fd == (-1))
		return (-1);
	printf("%s", readfile(fd));
	close(fd);
}