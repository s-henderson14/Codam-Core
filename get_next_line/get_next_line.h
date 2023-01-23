/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:16 by shenders          #+#    #+#             */
/*   Updated: 2023/01/23 12:25:14 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdbool.h>

char	*get_next_line(int fd);

char	*readfile(int fd, char *txt_cont);

char	*newline_present(char *txt);

char	*bytes_after_newline(char *txt);

char	*ft_strjoin(char *s1, char *s2, bool free_s1);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c);

void	*ft_memmove(void *dst, const void *src, size_t len);

size_t	ft_strlen(const char *s);

#endif