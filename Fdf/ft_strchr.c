/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:20:16 by shenders      #+#    #+#                 */
/*   Updated: 2022/11/13 17:18:52 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{	
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char) c == '\0')
		return ((char *) s);
	else
		return (0);
}

/*int	main(void)
{
	char	string[] = "teste";
	
	printf("%s\n", ft_strchr(string, '\0'));
	printf("\n");
	printf("%s\n", strchr(string, '\0'));
}*/
