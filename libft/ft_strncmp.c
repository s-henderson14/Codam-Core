/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:22:14 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/19 17:59:09 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while ((p1[i] || p2[i]) && i < n)
	{
		if (p1[i] - p2[i] == 0)
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "test";
	char	s2[] = "teste";
	char	s3[] = "tr";
	unsigned int	n = 2;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", ft_strncmp(s1, s3, n));
	printf("\n");
	printf("%d\n", strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s3, n));
}*/
