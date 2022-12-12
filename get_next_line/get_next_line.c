/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:09 by shenders          #+#    #+#             */
/*   Updated: 2022/12/12 11:38:30 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_utils.c"

//Dhamma.txt is 212 bytes
#ifndef BUFFER_SIZE 
#	define BUFFER_SIZE 7
#endif

char	*find_new_line(char *txt, int c)
{
	int	i;

	i = 0;
	if (!txt[i])
		return (NULL);
	while (txt[i])
	{	
		if (txt[i] == (char)c)
			return (ft_substr(txt, 0, i + 1));
		i++;
	}	
	return (NULL);			
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
			else if (line[i] != '\0')
				line_end = ft_substr(line, i, strlen(line) - i);	
			return (line_end);
		}
		i++;
	}		
	return (strdup(""));
}

char	*get_next_line(int fd)
{	
	static char	buf[BUFFER_SIZE + 1];
 	char	*line;
	static char	*nextline;

	if (nextline != 0)
		line = nextline;
	else
		line = strdup("");	
	while (read(fd, buf, BUFFER_SIZE) > 0) // --------------------> while there is something to read and read is successful.
	{	
		if (find_new_line(buf, '\n') == NULL) //------------------> if we don't find a new line character within the contents of the buffer.
			line = ft_strjoin(line, buf); //----------------------> join the contents of 'line' with contents of the buffer.
		else
		{	
			line = ft_strjoin(line, find_new_line(buf, '\n')); //-> on success, find_new_line () will return a string from the buffer. This string is everything read before the newline character and the newline character.
			nextline = linecut(buf, '\n');
			return (line);
		} 
	}
	return (line);	//-------------------------------------------> if read() failed |
}

int	main(void)
{
	int	fd;
	
	fd = open("dhamma.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	if (get_next_line(fd) == NULL)
		return(-1);
	return (0);		
}