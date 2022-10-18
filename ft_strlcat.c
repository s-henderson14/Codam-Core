/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:46:54 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/18 19:43:41 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	int		i;

	d_len = strlen(dst);
	s_len = strlen(src);
	i = 0;
	if (dstsize == 0)
		return (s_len);
	else if (dstsize < d_len)
		return (s_len + dstsize);
	else
	{	
		while (*(src + i) != '\0' && d_len + 1 < dstsize)
		{	
			*(dst + d_len) = *(src + i);
			d_len++;
			i++;
		}
	}
	*((dst) + d_len) = '\0';
	return (d_len + s_len);
}

/*int	main(void)
{
	char	dest[12] = "Super";
	const char	src[] = "Cat";
	size_t	n = 7;

    printf("%lu\n", ft_strlcat(dest, src, n));
	printf("%lu\n", strlcat(dest, src, n));
}*/
