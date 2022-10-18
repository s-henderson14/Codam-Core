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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{	
	size_t	d_len;
	size_t	s_len;
	int		i;

	d_len = strlen(dst);
	s_len = strlen(src);
	i = 0;
	if (dstsize < s_len)
		return (s_len);
	else
	{	
		while (*(src + i) != '\0' && d_len < dstsize)
		{	
			*(dst + i) = *(src + i);
			i++;
			d_len++;
		}
		*(dst + i) = '\0';
		return (s_len);
	}	
}
/*int	main()
{
	char 	dstring[10] = "";
	char	sstring[] = "Copy me";

	printf("%lu", ft_strlcpy(dstring, sstring, 7));
	printf("%lu", strlcpy(dstring, sstring, 7));
}*/	
