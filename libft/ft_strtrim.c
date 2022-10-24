/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 10:57:40 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/24 14:57:32 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ps1;
	char			*pset;
	char			*trmd;
	unsigned int	i;

	i = 0;
	ps1 = (char *) s1;
	pset = (char *) set;
	trmd = (char *) malloc(sizeof(char) * ft_strlen(s1));
	if (!trmd)
		return (0);
	if (ft_strncmp(s1, set, ft_strlen (set)) == 0 && ft_strncmp(s1 + (ft_strlen(s1) - ft_strlen(set)) , set, ft_strlen(set) == 0))
		trmd = ft_substr(s1, ft_strlen(set), ft_strlen(s1) - ft_strlen(set) * 2);
	else if (ft_strncmp(s1, set, ft_strlen(set) == 0))
		trmd = ft_substr(s1, ft_strlen(set), ft_strlen(s1) - ft_strlen(set));
	else if (ft_strncmp(s1 + (ft_strlen(s1) - ft_strlen(set)), set, ft_strlen(set)) == 0)	
		trmd = ft_substr(s1, i, ft_strlen(s1) - ft_strlen(set));
	else
		return (0);
	return (trmd);
}

/*int	main()
{
	char	s1[] = "Hello";
	char	set[] = "lo";

	printf("%s", ft_strtrim(s1, set));
}*/
