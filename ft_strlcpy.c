/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 15:50:27 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/16 20:16:36 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{	
	size_t	s_len;
	size_t	i;
	char	*ps;
	
	ps = (char *)src;
	s_len = ft_strlen(src);
	i = 0;
	if (dstsize < 1)
		return (s_len);
	
	while (dstsize - 1 > 0 && ps[i])
	{	
		dst[i] = ps[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (s_len);
}

/*int	main()
{
	char 	dstring[10] = "";
	char	sstring[] = "Copy me";

	printf("%lu", ft_strlcpy(dstring, sstring, 8));
	printf("%lu", strlcpy(dstring, sstring, 8));
}*/	
