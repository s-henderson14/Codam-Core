/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 11:23:03 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/24 14:44:31 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd);

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{	
		write(fd, s, 1);
		s++;
	}
}

/*int	main(void)
{
	ft_putstr_fd("Hello", 1);
}*/
