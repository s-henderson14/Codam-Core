/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:40:29 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:31:59 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{	
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
