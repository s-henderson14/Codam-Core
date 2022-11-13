/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:46:54 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:16:56 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>
#include "libft.h"
/*#include <unistd.h>*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	char	*ps;

	s_len = ft_strlen(src);
	if (dst == 0 && dstsize == 0)
		return (s_len);
	ps = (char *) src;
	d_len = ft_strlen(dst);
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
