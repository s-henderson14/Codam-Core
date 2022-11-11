/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:29:44 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/07 14:56:45 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (!pdst && !psrc)
		return (0);
	if (pdst < psrc)
		ft_memcpy(dst, src, len);
	else
	{	
		while (len > 0)
		{	
			pdst[len - 1] = psrc [len - 1];
			len--;
		}
	}	
	return (dst);
}
/*int	main(void)
{
	char	dest[] = "Start";
	char	src[] = "prt";

	printf("%s\n", ft_memmove(dest, src, 3 * sizeof(char)));
	printf("%s\n", memmove(dest, src, 3 * sizeof(char)));
}*/
