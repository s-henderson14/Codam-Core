/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:09 by shenders          #+#    #+#             */
/*   Updated: 2022/12/10 12:12:04 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_utils.c"

//Dhamma.txt is 212 bytes
#ifndef BUFFER_SIZE 
#	define BUFFER_SIZE 10
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
			return (ft_substr(txt, 0, i));
		i++;
	}
	if (txt[i] == '\0')		
		return (0);			
}

char	*get_next_line(int fd)
{	
	static char buf[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	if (fd < 1)
		return(NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0) // While read is successful
	{	
		if (find_new_line(buf, '\n') == (NULL)) // if error occurs when searching for '\n'. Free buffer and return error value.
		{	
			free(buf); // free the allcoated buffer
			break;
		}
		else if (find_new_line(buf, '\n') == 0) // if no occurences of a newline character are found return the contents which were read into the buffer. 
		{	
			buf[BUFFER_SIZE] = '\0';	
			return (buf);
		}
		else
		{	
			line = find_new_line(buf, '\n'); //on success, find_new_line () will return a string from the buffer. This string is everything read before the newline character.
			line = ft_strjoin(line, '\n'); // adds newline character to the end of the 'line', the string returned from find_new_line()
			return(line);
		}
	}
	return (NULL);	// if read() failed || or read () had nothing to read || or find_new_line failed 
}

int	main(void)
{
	int	fd;
	
	fd = open("dhamma.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd);	
}