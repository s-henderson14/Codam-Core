/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:29:44 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/12 16:16:57 by shenders      ########   odam.nl         */
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
	char			*buff;
	unsigned int	i;

	pdst = (char *) dst;
	psrc = (char *) src;
	buff = (char *) malloc (len * sizeof (char));
	i = 0;
	if (psrc == NULL)
		return (NULL);
	while (i < len)
	{
		buff[i] = psrc[i];
		pdst[i] = buff[i];
		i++;
	}
	return (pdst);
}
//still need to free memory after using malloc

/*int	main(void)
{
	char	str1[] = "Start";
	char	str2[] = "Art";

	printf("%s\n", ft_memmove(str1, str2, 3 * sizeof(char)));
	printf("%s\n", memmove(str1, str2, 3 * sizeof(char)));
	printf("\n");
	printf("%s\n", memcpy(str1, str2, 3 * sizeof(char)));
}*/
