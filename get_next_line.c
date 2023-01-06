/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:09 by shenders          #+#    #+#             */
/*   Updated: 2023/01/06 18:20:41 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{	
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!reader(fd, BUFFER_SIZE))
		return (NULL);
	else 
		return (get_line(reader(fd, BUFFER_SIZE), '\n'));
}

int	main(void)
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
}