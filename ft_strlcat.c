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

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	int	i;
	char	*ps;
	
	ps = (char *) src;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (dstsize - d_len < s_len)
		return (s_len + ft_strlen(dst));	
	while (dstsize >= (d_len + 1))
	{	
		dst[d_len + i] = ps[i];
		i++;
		dstsize--;
	}
	dst[d_len + i] = '\0';
	return (dstsize + s_len);
}

/*int	main(void)
{
	char	dest[14] = "a";
	const char src[] = "lorem ipsum dolor sit amet";
	size_t	n = 15 ;

    printf("%lu\n", ft_strlcat(dest, src, n));
}*/
