/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:46:54 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/24 09:48:27 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	char	*ps;

	ps = (char *) src;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	while (i < s_len && i < (dstsize - d_len - 1))
	{	
		dst[d_len + i] = ps[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/*int	main(void)
{
	char	dest[15]= "";

	memset(dest, 'r', 15);
    printf("%lu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);
}*/
