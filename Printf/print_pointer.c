/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:09 by shenders          #+#    #+#             */
/*   Updated: 2022/12/05 13:41:38 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <unistd.h>

static int	strl(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static int	num_len(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
		count++;
	while (p != 0)
	{
		count++;
		p /= 16;
	}
	return (count);
}

int	print_pointer(void *add)
{
	int				len;
	char			*hex;
	char			*str;
	unsigned long	i;

	i = (unsigned long) add;
	len = num_len(i);
	hex = "0123456789abcdef";
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (free(str), -1);
	str[len] = '\0';
	if (i == 0)
		str[--len] = hex[0];
	while (i != 0)
	{
		str[--len] = hex[i % 16];
		i = i / 16;
	}
	len = strl(str);
	write(1, "0x", 2);
	if (print_string(str) == -1)
		return (-1);
	free(str);
	return (len + 2);
}

/*int    main(void)
{   
	ft_printf("%p", "");
	printf("%p", (void *)ptr);
}*/