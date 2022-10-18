/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:22:14 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/12 12:30:09 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] - s2[i] == 0)
			i++;
		else
			return (s1[i] - s2[i]);
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
