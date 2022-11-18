/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_conversion.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:07:01 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/17 16:01:11 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	s_conversion(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}

int	main()
{
	char	*s = "Hello Sean";

	printf("%d", s_conversion(s, 1));
}
