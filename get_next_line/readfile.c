/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:38:11 by shenders          #+#    #+#             */
/*   Updated: 2022/12/10 14:57:37 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE 
#	define BUFFER_SIZE 10
#endif

char	*readfile (int fd)
{	
	//If no buffer size is defined with -D 
	static char buf[BUFFER_SIZE + 1];
	//static char	buf[250]; ///----------------------------buf is declared with space for 250 individual characters
	//static int	read_count;
	
	if (fd == -1)
		return (NULL);
	if (fd != '\0')	
	{	
		read(fd, buf, sizeof(buf)); // reads 226 bytes from the open file pointed to by the fd. These 226 bytes are then read into the static char 'buf'
		buf[225] = '\0';
	}
	return (buf);	
}

int	main(void)
{
	int	fd;

	fd = open("dhamma.txt", O_RDWR | O_APPEND);
	if (fd == (-1))
		return (-1);
	printf("%s\n\n\n\n", readfile(fd));
	write(fd, "Gautamas Book", 13);
	close(fd); // Lines 58 - 63 will open the file dhamma.txt, read the file related to the file descriptor produced by open () and then close again.
	fd = open("dhamma.txt", O_RDONLY);
	if (fd == (-1))
		return (-1);
	printf("%s", readfile(fd));
	close(fd); // Lines 64 - 68 will open the file again and read the newly appended words which were passed to write ().
}