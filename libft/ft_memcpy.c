/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 09:28:32 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/07 14:57:00 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *) dst;
	psrc = (char *) src;
	if (!psrc && !dst)
		return (0);
	while (n != 0)
	{	
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (dst);
}

/*int	main(void)
{
	char	dst[] = "Hello";
	char	src[] = "Tryit";

	printf("%s\n", ft_memcpy(dst, src, 3));
	printf("%s\n", memcpy(dst, src, 3));
	return (0);
}*/
