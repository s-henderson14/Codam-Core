/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:01:00 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/14 13:24:39 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while (i < n)
	{	
		if (ps1[i] - ps2[i] == 0)
			i++;
		else
			return (ps1[i] - ps2[i]);
	}
	return (0);
}	

/*int	main(void)
{
	char	string1[] = "Currently on track";
	char	string2[] = "Currently or track";
	
	printf("%d\n", ft_memcmp(string1, string2, 11));
	printf("%d\n", ft_memcmp(string1, string2, 12));
	printf("%d\n", ft_memcmp(string1, string2, 0));
	printf("\n");
	printf("%d\n", memcmp(string1, string2, 11));
	printf("%d\n", memcmp(string1, string2, 12));
	printf("%d\n", memcmp(string1, string2, 0));	
}*/
