/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:46:54 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/12 16:13:31 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (*src == '\0')
		return (dstsize);
	while (*dst != '\0')
		dst++;
	while (i < dstsize)
	{	
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (strlen(dst));
}

int	main(void)
{
	char	dest[] = "Super";
	char	src[] = "Cat";
	//char	sr0[] = "";
	size_t	nb = 3;

	//printf("%lu", ft_strlcat(dest, src, nb));
	printf("%lu", ft_strlcat(dest, src, nb));
	//printf("%lu", ft_strlcat(dest, sr0, nb));
	printf("\n");
	//printf("%lu", strlcat(dest, src, nb));
	printf("%lu", strlcat(dest, src, nb));
	//printf("%lu", strlcat(dest, sr0, nb));
}
