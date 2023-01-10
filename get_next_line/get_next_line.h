/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sean <Sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:16 by shenders          #+#    #+#             */
/*   Updated: 2023/01/09 18:31:40 by Sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*get_next_line(int fd);

char	*readfile(int fd, char *line);

char	*getline_(char *txt);

char	*over_read(char *txt);

char	*ft_strjoin(char *s1, char *s2);

char	*join_and_free(char *line, char *buf);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

#endif