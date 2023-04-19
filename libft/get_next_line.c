/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:02:38 by Sean              #+#    #+#             */
/*   Updated: 2023/01/24 16:56:52 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*newline_present(char *txt)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!txt)
		return (free(txt), NULL);
	while (txt[i])
	{	
		if (txt[i] == '\n')
		{	
			line = get_substr(txt, 0, i + 1);
			if (!line)
				return (free(txt), NULL);
			return (free(txt), line);
		}
		i++;
	}
	return (txt);
}

char	*bytes_after_newline(char *txt)
{
	int		i;
	char	*after_newline;

	i = 0;
	while (txt[i])
	{	
		if (txt[i] == '\n')
		{	
			i++;
			if (!txt[i])
				return (NULL);
			after_newline = get_substr(txt, i, (ft_strlen(txt) - i));
			if (!after_newline)
				return (NULL);
			return (after_newline);
		}
		i++;
	}
	return (NULL);
}

char	*readfile(int fd, char *txt_cont)
{
	char	*buffer;
	int		bytes_read;

	if (txt_cont == NULL)
		return (free(txt_cont), NULL);
	bytes_read = BUFFER_SIZE;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(txt_cont), NULL);
	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		txt_cont = gnline_join(txt_cont, buffer, 1);
		if (!txt_cont || txt_cont[0] == '\0')
			return (free(buffer), free(txt_cont), NULL);
		if (ft_strchr(txt_cont, '\n'))
			break ;
	}
	if (txt_cont[0] == '\0' || !txt_cont)
		return (free(buffer), free(txt_cont), NULL);
	return (free(buffer), txt_cont);
}

char	*get_next_line(int fd)
{	
	char		*txt_container;
	static char	*excess;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{	
		free(excess);
		excess = NULL;
		return (NULL);
	}
	txt_container = malloc(sizeof(char));
	if (!txt_container)
		return (free(excess), NULL);
	txt_container[0] = '\0';
	if (excess)
		txt_container = gnline_join(txt_container, excess, 1);
	txt_container = readfile(fd, txt_container);
	if (!txt_container || !txt_container[0])
		return (free(excess), free(txt_container), NULL);
	if (excess)
		free(excess);
	excess = bytes_after_newline(txt_container);
	txt_container = newline_present(txt_container);
	if (!txt_container)
		return (NULL);
	return (txt_container);
}

// void l (void)
// {
// 	system("leaks a.out");
// }

// int	main(void)
// {	
// 	//atexit(l);
// 	int fd = open("test.txt", O_RDONLY);

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	return (0);
// }
