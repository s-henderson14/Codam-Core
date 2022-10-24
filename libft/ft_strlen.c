/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:36:26 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/14 13:30:43 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int	main(void)
{
	printf("%lu", ft_strlen("Hello"));
	printf("%lu", ft_strlen("Hello"));
	printf("\n");
	printf("%lu", strlen("Hello"));
	printf("%lu", strlen("Hello"));
}*/
