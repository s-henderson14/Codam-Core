/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:09 by shenders          #+#    #+#             */
/*   Updated: 2022/11/25 09:57:36 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include <string.h>

static int    num_len(unsigned long p)
{
    int    count;

    count = 0;
    while (p != 0)
    {    
        count++;
        p /= 16;
    }
    return (count);
}

int    print_pointer(void* n)
{    
    int        len;
    char    *hex;
    char    *str;
	unsigned long	i;

	i = (unsigned long) &n;
    len = num_len(i);
    hex = "0123456789abcdef";
    str = malloc(len * sizeof(char) + 1);
    if (!str)
        return (0);
    str[len] = '\0';
    while (i != 0)
    {    
        str[--len] = hex[i % 16];
        i = i / 16;
    }
    write(1, "0x", 2);
    print_string(str);
    return ((int)strlen(str));
}

/*int    main(void)
{    
    void     *ptr;

    ptr = NULL;
    printf("%p\n", &ptr);
    print_pointer(&ptr);
}*/