/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 08:31:51 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/06 09:28:11 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
//Test using Python Tutor or printf(ft_bzero(string, 3))
//and change function declaration to pointer.
void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*zero;

	zero = s;
	while (n != 0)
	{	
		*zero = '\0';
		zero++;
		n--;
	}
}

/*int	main(void)
{
	char	string[] = "Hello";

	ft_bzero(string, 1);
}*/
