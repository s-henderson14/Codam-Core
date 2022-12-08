/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:09 by shenders          #+#    #+#             */
/*   Updated: 2022/12/08 13:46:04 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//Dhamma.txt is 212 bytes

char	*get_next_line(int fd)
{
	size_t	buf_size;
	void	*buf;
	
	buf = NULL;
	buf_size = 20;
	if (!fd)
	 	return (-1);
	if (read(fd, buf, buf_size) == -1)
		return (-1);
		
		
	
}

int	main(void)
{
	int	fd;
	
	fd = open("dhamma.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd);	
		
	
}