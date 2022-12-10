/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:09 by shenders          #+#    #+#             */
/*   Updated: 2022/12/10 13:01:15 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_utils.c"

//Dhamma.txt is 212 bytes
#ifndef BUFFER_SIZE 
#	define BUFFER_SIZE 40
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
	return (0);			
}

char	*get_next_line(int fd)
{	
	static char buf[BUFFER_SIZE + 1];
	char	*line;

	if (fd < 1)
		return(NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0) // While there is something to read and read is successful'
	{	
		line = NULL;
		if ((find_new_line(buf, '\n') == (NULL) || 0)) // if error occurs when searching for '\n'. Free buffer and return error value.
			break;
		else
		{	
			line = find_new_line(buf, '\n'); //on success, find_new_line () will return a string from the buffer. This string is everything read before the newline character.
			line = ft_strjoin(line, "\n"); // adds newline character to the end of the 'line', the string returned from find_new_line()
			return(line);
		}
	}
	if (read(fd,buf, BUFFER_SIZE) == 0)
	{	
		buf[BUFFER_SIZE] = '\0';
		return(buf);
	}
	return (NULL);	// if read() failed || find_new_line() failed 
}

int	main(void)
{
	int	fd;
	
	fd = open("dhamma.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	if (get_next_line(fd) == NULL)
		return(-1);
	else 
		return (0);		
}