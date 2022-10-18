/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 19:28:31 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/18 20:31:17 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *) malloc (count * size);
	if (!mem)
		return (NULL);
	memset(mem, 0, count);
	return (mem);
}

/*int main(void)
{
    printf("%s\n", ft_calloc(5, 1));
    printf("%s\n", calloc(5, 1));
}*/
