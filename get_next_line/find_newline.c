#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_utils.c"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

char	*find_new_line(char *txt, int c)
{
	int	i;

	i = 0;
	if (!txt[i])
		return (NULL);
	while (txt[i])
	{	
		if (txt[i] == (char)c)
			return (ft_substr(txt, 0, i));
		i++;
	}
	if (txt[i] == '\0')		
		return (0);			
}

char	*readfile (int fd)
{	
	static char buf[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{	
		if (find_new_line(buf, '\n') == (-1)) // if error occurs when searching for '\n'. Free buffer and return error value.
		{	
			free(buf);
			break;
		}
		else if (find_new_line(buf, '\n') == 0) // if no occurences of a newline character are found (due to complete absence or EOF) return buf. 
		{	
			buf[BUFFER_SIZE] = '\0';	
			return (buf);
		}
		else
			return(ft_substr(line, 0, find_new_line(buf, '\n')));
	}
	return (NULL);	
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