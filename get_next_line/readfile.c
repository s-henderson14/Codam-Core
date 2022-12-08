/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:38:11 by shenders          #+#    #+#             */
/*   Updated: 2022/12/08 15:43:41 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <libc.h>

//#define BUFFER_SIZE 10

char	*readfile (int fd)
{	
	//static char buf[BUFFER_SIZE + 1]
	static char	buf[212];
	int		i;
	i = 0;
	if (fd == -1)
		return (NULL);
	if (fd != EOF)	
	{	
		read(fd, buf, 212);
		buf[211] = '\0';
	}
	return (buf);	
}

int	main(void)
{
	int	fd;

	fd = open("dhamma.txt", O_RDONLY );
	if (fd == (-1))
		return (-1);
	printf("%s", readfile(fd));
}