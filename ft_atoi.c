/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 17:49:25 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/18 20:30:32 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	minus;

	index = 0;
	number = 0;
	minus = 1;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == 45 || str[index] == 43)
	{
		if (str[index] == 45)
			minus = minus * (-1);
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
	{
		number = (number * 10) + (str[index] - '0');
		index++;
	}
	if (number > INT_MAX)
		return (-1);
	else if (number < INT_MIN)
		return (0);
	return (number * minus);
}

/*int   main(void)
{
    //char  string[] = "13141319";
    //char  string1[] = "    1345adf5";
    //char  string2[] = " ++-  3456 a";
    //char  string3[] = "";
    //char  string4[] = "    ++-3456 f";
    //char  string5[] = "   ++--5678";

    printf("%d", ft_atoi(string5));
}*/
