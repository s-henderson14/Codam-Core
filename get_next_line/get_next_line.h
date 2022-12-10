/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:16 by shenders          #+#    #+#             */
/*   Updated: 2022/12/10 14:59:02 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif*/

	#include <stdlib.h>

char	*get_next_line(int fd);

char    *ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

