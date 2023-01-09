/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sean <Sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:02:38 by Sean              #+#    #+#             */
/*   Updated: 2023/01/09 01:07:31 by Sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include "get_next_line_utils.c"
#include <string.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 10
#endif

char    *get_next_line(int fd)
{
    char    *txt_container;
    static char    *excess;
    char    buffered_data[BUFFER_SIZE + 1];
    int     bytes_to_read;
    
    if (fd < 1 || BUFFER_SIZE < 1)
        return (NULL);
    txt_container =  malloc(sizeof(char) * 1);
    if (!txt_container)
        return (free(txt_container), NULL); 
    if(excess > 0)
            txt_container = excess;   
    bytes_to_read = 1;
    while (bytes_to_read)
    {
        bytes_to_read = read(fd, buffered_data, BUFFER_SIZE);
        if (bytes_to_read == -1)
            return (NULL);
        buffered_data[bytes_to_read] = '\0';
        if (!newline_present(buffered_data))
            txt_container = ft_strjoin(txt_container, buffered_data);
        else if (newline_present(buffered_data))
        {   
            excess = bytes_after_newline(buffered_data);
            txt_container = (ft_strjoin(txt_container, newline_present(buffered_data)));
            break ;
        }
    }
    return (txt_container);
}

/*int main(void)
{   
    int fd;

    fd = open("dhamma.txt", O_RDONLY);
    if (fd == (-1))
        return (-1);
    printf("%s", readfile(fd)); 
    printf("%s", readfile(fd));
    printf("%s", readfile(fd));
    printf("%s", readfile(fd)); 
    return (0);
}*/
