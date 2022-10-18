/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:29:44 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/16 19:27:56 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pdst;
	char			*psrc;

	pdst = (char *) dst;
	psrc = (char *) src;
	if (psrc == NULL)
		return (NULL);
	while (len > 0)
	{
		pdst[len - 1] = psrc[len - 1];
		len--;
	}
	return (pdst);
}

/*int	main(void)
{
	char	str1[] = "Start";
	char	str2[] = "yoo";

	printf("%s\n", ft_memmove(str1, str2, 3 * sizeof(char)));
	printf("%s\n", memmove(str1, str2, 3 * sizeof(char)));
	printf("\n");
}*/
